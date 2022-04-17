
"use strict";

let MFIOConfig = require('./MFIOConfig.js')
let QueryDroneVersion = require('./QueryDroneVersion.js')
let MissionWpGetInfo = require('./MissionWpGetInfo.js')
let MissionHpUpdateYawRate = require('./MissionHpUpdateYawRate.js')
let MFIOSetValue = require('./MFIOSetValue.js')
let MissionWpGetSpeed = require('./MissionWpGetSpeed.js')
let MissionWpSetSpeed = require('./MissionWpSetSpeed.js')
let MissionStatus = require('./MissionStatus.js')
let StereoVGASubscription = require('./StereoVGASubscription.js')
let SetHardSync = require('./SetHardSync.js')
let MissionHpUpload = require('./MissionHpUpload.js')
let SetLocalPosRef = require('./SetLocalPosRef.js')
let SetupCameraStream = require('./SetupCameraStream.js')
let SDKControlAuthority = require('./SDKControlAuthority.js')
let DroneTaskControl = require('./DroneTaskControl.js')
let MissionHpResetYaw = require('./MissionHpResetYaw.js')
let CameraAction = require('./CameraAction.js')
let MissionWpAction = require('./MissionWpAction.js')
let MissionHpGetInfo = require('./MissionHpGetInfo.js')
let MissionHpUpdateRadius = require('./MissionHpUpdateRadius.js')
let SendMobileData = require('./SendMobileData.js')
let MissionHpAction = require('./MissionHpAction.js')
let StereoDepthSubscription = require('./StereoDepthSubscription.js')
let DroneArmControl = require('./DroneArmControl.js')
let Activation = require('./Activation.js')
let MissionWpUpload = require('./MissionWpUpload.js')
let Stereo240pSubscription = require('./Stereo240pSubscription.js')

module.exports = {
  MFIOConfig: MFIOConfig,
  QueryDroneVersion: QueryDroneVersion,
  MissionWpGetInfo: MissionWpGetInfo,
  MissionHpUpdateYawRate: MissionHpUpdateYawRate,
  MFIOSetValue: MFIOSetValue,
  MissionWpGetSpeed: MissionWpGetSpeed,
  MissionWpSetSpeed: MissionWpSetSpeed,
  MissionStatus: MissionStatus,
  StereoVGASubscription: StereoVGASubscription,
  SetHardSync: SetHardSync,
  MissionHpUpload: MissionHpUpload,
  SetLocalPosRef: SetLocalPosRef,
  SetupCameraStream: SetupCameraStream,
  SDKControlAuthority: SDKControlAuthority,
  DroneTaskControl: DroneTaskControl,
  MissionHpResetYaw: MissionHpResetYaw,
  CameraAction: CameraAction,
  MissionWpAction: MissionWpAction,
  MissionHpGetInfo: MissionHpGetInfo,
  MissionHpUpdateRadius: MissionHpUpdateRadius,
  SendMobileData: SendMobileData,
  MissionHpAction: MissionHpAction,
  StereoDepthSubscription: StereoDepthSubscription,
  DroneArmControl: DroneArmControl,
  Activation: Activation,
  MissionWpUpload: MissionWpUpload,
  Stereo240pSubscription: Stereo240pSubscription,
};
