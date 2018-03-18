/***************************************************************************
This file is part of Project Apollo - NASSP
Copyright 2018

Lunar Module Caution and Warning Electronics Assembly (Header)

Project Apollo is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

Project Apollo is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Project Apollo; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

See http://nassp.sourceforge.net/license/ for more details.

**************************************************************************/

#pragma once

class LEM;

class LEM_CWEA : public e_object {
public:
	LEM_CWEA(SoundLib &s);
	void Init(LEM *l, e_object *cwea, e_object *ma);
	void SaveState(FILEHANDLE scn, char *start_str, char *end_str);
	void LoadState(FILEHANDLE scn, char *end_str);
	bool IsPowered();
	bool IsMAPowered();
	void TimeStep(double simdt);
	void SystemTimestep(double simdt);
	void SetMasterAlarm(bool alarm);
	void PushMasterAlarm();

	bool CheckMasterAlarmMouseClick(int event);
	void RenderMasterAlarm(SURFHANDLE surf, SURFHANDLE alarmLit, SURFHANDLE border);
	void RedrawLeft(SURFHANDLE sf, SURFHANDLE ssf);
	void RedrawRight(SURFHANDLE sf, SURFHANDLE ssf);

protected:
	int LightStatus[5][8];		// 1 = lit, 2 = not
	int WaterWarningDisabled;   // FF for this
	bool MasterAlarm;

	e_object *cwea_pwr;
	e_object *ma_pwr;

	SoundLib &soundlib;
	Sound MasterAlarmSound;

	LEM *lem;					// Pointer at LEM
};