// Generated by gencpp from file dji_sdk/CameraAction.msg
// DO NOT EDIT!


#ifndef DJI_SDK_MESSAGE_CAMERAACTION_H
#define DJI_SDK_MESSAGE_CAMERAACTION_H

#include <ros/service_traits.h>


#include <dji_sdk/CameraActionRequest.h>
#include <dji_sdk/CameraActionResponse.h>


namespace dji_sdk
{

struct CameraAction
{

typedef CameraActionRequest Request;
typedef CameraActionResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct CameraAction
} // namespace dji_sdk


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::dji_sdk::CameraAction > {
  static const char* value()
  {
    return "cffa80c600cf5ffacb2c7279944f208e";
  }

  static const char* value(const ::dji_sdk::CameraAction&) { return value(); }
};

template<>
struct DataType< ::dji_sdk::CameraAction > {
  static const char* value()
  {
    return "dji_sdk/CameraAction";
  }

  static const char* value(const ::dji_sdk::CameraAction&) { return value(); }
};


// service_traits::MD5Sum< ::dji_sdk::CameraActionRequest> should match 
// service_traits::MD5Sum< ::dji_sdk::CameraAction > 
template<>
struct MD5Sum< ::dji_sdk::CameraActionRequest>
{
  static const char* value()
  {
    return MD5Sum< ::dji_sdk::CameraAction >::value();
  }
  static const char* value(const ::dji_sdk::CameraActionRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::dji_sdk::CameraActionRequest> should match 
// service_traits::DataType< ::dji_sdk::CameraAction > 
template<>
struct DataType< ::dji_sdk::CameraActionRequest>
{
  static const char* value()
  {
    return DataType< ::dji_sdk::CameraAction >::value();
  }
  static const char* value(const ::dji_sdk::CameraActionRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::dji_sdk::CameraActionResponse> should match 
// service_traits::MD5Sum< ::dji_sdk::CameraAction > 
template<>
struct MD5Sum< ::dji_sdk::CameraActionResponse>
{
  static const char* value()
  {
    return MD5Sum< ::dji_sdk::CameraAction >::value();
  }
  static const char* value(const ::dji_sdk::CameraActionResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::dji_sdk::CameraActionResponse> should match 
// service_traits::DataType< ::dji_sdk::CameraAction > 
template<>
struct DataType< ::dji_sdk::CameraActionResponse>
{
  static const char* value()
  {
    return DataType< ::dji_sdk::CameraAction >::value();
  }
  static const char* value(const ::dji_sdk::CameraActionResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // DJI_SDK_MESSAGE_CAMERAACTION_H
