// Generated by gencpp from file dji_sdk/DroneTaskControl.msg
// DO NOT EDIT!


#ifndef DJI_SDK_MESSAGE_DRONETASKCONTROL_H
#define DJI_SDK_MESSAGE_DRONETASKCONTROL_H

#include <ros/service_traits.h>


#include <dji_sdk/DroneTaskControlRequest.h>
#include <dji_sdk/DroneTaskControlResponse.h>


namespace dji_sdk
{

struct DroneTaskControl
{

typedef DroneTaskControlRequest Request;
typedef DroneTaskControlResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct DroneTaskControl
} // namespace dji_sdk


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::dji_sdk::DroneTaskControl > {
  static const char* value()
  {
    return "ab91c4042653ca6868c5907bf22e4741";
  }

  static const char* value(const ::dji_sdk::DroneTaskControl&) { return value(); }
};

template<>
struct DataType< ::dji_sdk::DroneTaskControl > {
  static const char* value()
  {
    return "dji_sdk/DroneTaskControl";
  }

  static const char* value(const ::dji_sdk::DroneTaskControl&) { return value(); }
};


// service_traits::MD5Sum< ::dji_sdk::DroneTaskControlRequest> should match 
// service_traits::MD5Sum< ::dji_sdk::DroneTaskControl > 
template<>
struct MD5Sum< ::dji_sdk::DroneTaskControlRequest>
{
  static const char* value()
  {
    return MD5Sum< ::dji_sdk::DroneTaskControl >::value();
  }
  static const char* value(const ::dji_sdk::DroneTaskControlRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::dji_sdk::DroneTaskControlRequest> should match 
// service_traits::DataType< ::dji_sdk::DroneTaskControl > 
template<>
struct DataType< ::dji_sdk::DroneTaskControlRequest>
{
  static const char* value()
  {
    return DataType< ::dji_sdk::DroneTaskControl >::value();
  }
  static const char* value(const ::dji_sdk::DroneTaskControlRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::dji_sdk::DroneTaskControlResponse> should match 
// service_traits::MD5Sum< ::dji_sdk::DroneTaskControl > 
template<>
struct MD5Sum< ::dji_sdk::DroneTaskControlResponse>
{
  static const char* value()
  {
    return MD5Sum< ::dji_sdk::DroneTaskControl >::value();
  }
  static const char* value(const ::dji_sdk::DroneTaskControlResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::dji_sdk::DroneTaskControlResponse> should match 
// service_traits::DataType< ::dji_sdk::DroneTaskControl > 
template<>
struct DataType< ::dji_sdk::DroneTaskControlResponse>
{
  static const char* value()
  {
    return DataType< ::dji_sdk::DroneTaskControl >::value();
  }
  static const char* value(const ::dji_sdk::DroneTaskControlResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // DJI_SDK_MESSAGE_DRONETASKCONTROL_H
