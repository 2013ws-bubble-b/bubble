/****************************************************************************
*                                                                           *
*  OpenNI 1.x Alpha                                                         *
*  Copyright (C) 2011 PrimeSense Ltd.                                       *
*                                                                           *
*  This file is part of OpenNI.                                             *
*                                                                           *
*  OpenNI is free software: you can redistribute it and/or modify           *
*  it under the terms of the GNU Lesser General Public License as published *
*  by the Free Software Foundation, either version 3 of the License, or     *
*  (at your option) any later version.                                      *
*                                                                           *
*  OpenNI is distributed in the hope that it will be useful,                *
*  but WITHOUT ANY WARRANTY; without even the implied warranty of           *
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the             *
*  GNU Lesser General Public License for more details.                      *
*                                                                           *
*  You should have received a copy of the GNU Lesser General Public License *
*  along with OpenNI. If not, see <http://www.gnu.org/licenses/>.           *
*                                                                           *
****************************************************************************/
#ifndef MY_OPEN_NI_H_
#define MY_OPEN_NI_H_

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <XnOpenNI.h>
#include <XnCodecIDs.h>
#include <XnCppWrapper.h>
#include <XnPropNames.h>

#include <sys/time.h>

#include "SceneDrawer.h"


//---------------------------------------------------------------------------
// Globals
//---------------------------------------------------------------------------

extern xn::Context g_Context;
extern xn::ScriptNode g_scriptNode;
extern xn::DepthGenerator g_DepthGenerator;
extern xn::UserGenerator g_UserGenerator;
extern xn::Player g_Player;

extern XnBool g_bNeedPose;
extern XnChar g_strPose[20];
extern XnBool g_bDrawBackground;
extern XnBool g_bDrawPixels;
extern XnBool g_bDrawSkeleton;
extern XnBool g_bPrintID;
extern XnBool g_bPrintState;

extern XnBool g_bPause;
extern XnBool g_bRecord;
extern XnBool g_bQuit;

// run from executive folder!
#define SAMPLE_XML_PATH "/home_nfs/2013ws_bubble_b/kinect/Data/SamplesConfig.xml"

#define XN_CALIBRATION_FILE_NAME "UserCalibration.bin"

#define CHECK_RC(nRetVal, what)										\
	if (nRetVal != XN_STATUS_OK)									\
	{																\
		printf("%s failed: %s\n", what, xnGetStatusString(nRetVal));\
		exit(nRetVal);												\
	}
	
	
//---------------------------------------------------------------------------
// Functions
//---------------------------------------------------------------------------

void InitOpenNI(int argc, char **argv);
void CleanupExit();

XnPoint3D getRightHandPosition(XnUserID user);
XnPoint3D getLeftHandPosition(XnUserID user);

// Callback: New user was detected
void XN_CALLBACK_TYPE User_NewUser(xn::UserGenerator& generator, XnUserID nId, void* pCookie);

// Callback: An existing user was lost
void XN_CALLBACK_TYPE User_LostUser(xn::UserGenerator& generator, XnUserID nId, void* pCookie);

// Callback: Detected a pose
void XN_CALLBACK_TYPE UserPose_PoseDetected(xn::PoseDetectionCapability& capability, const XnChar* strPose, XnUserID nId, void* pCookie);

// Callback: Started calibration
void XN_CALLBACK_TYPE UserCalibration_CalibrationStart(xn::SkeletonCapability& capability, XnUserID nId, void* pCookie);

// Callback: Finished calibration
void XN_CALLBACK_TYPE UserCalibration_CalibrationEnd(xn::SkeletonCapability& capability, XnUserID nId, XnBool bSuccess, void* pCookie);

// Callback:
void XN_CALLBACK_TYPE UserCalibration_CalibrationComplete(xn::SkeletonCapability& capability, XnUserID nId, XnCalibrationStatus eStatus, void* pCookie);

// Save calibration to file
void SaveCalibration();

// Load calibration from file
void LoadCalibration();


#endif











