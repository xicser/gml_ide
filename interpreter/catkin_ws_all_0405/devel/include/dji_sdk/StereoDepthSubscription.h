// Generated by gencpp from file dji_sdk/StereoDepthSubscription.msg
// DO NOT EDIT!


#ifndef DJI_SDK_MESSAGE_STEREODEPTHSUBSCRIPTION_H
#define DJI_SDK_MESSAGE_STEREODEPTHSUBSCRIPTION_H

#include <ros/service_traits.h>


#include <dji_sdk/StereoDepthSubscriptionRequest.h>
#include <dji_sdk/StereoDepthSubscriptionResponse.h>


namespace dji_sdk
{

struct StereoDepthSubscription
{

typedef StereoDepthSubscriptionRequest Request;
typedef StereoDepthSubscriptionResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct StereoDepthSubscription
} // namespace dji_sdk


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::dji_sdk::StereoDepthSubscription > {
  static const char* value()
  {
    return "6da41f0fc9c34988dbd56e6a11bddfdf";
  }

  static const char* value(const ::dji_sdk::StereoDepthSubscription&) { return value(); }
};

template<>
struct DataType< ::dji_sdk::StereoDepthSubscription > {
  static const char* value()
  {
    return "dji_sdk/StereoDepthSubscription";
  }

  static const char* value(const ::dji_sdk::StereoDepthSubscription&) { return value(); }
};


// service_traits::MD5Sum< ::dji_sdk::StereoDepthSubscriptionRequest> should match 
// service_traits::MD5Sum< ::dji_sdk::StereoDepthSubscription > 
template<>
struct MD5Sum< ::dji_sdk::StereoDepthSubscriptionRequest>
{
  static const char* value()
  {
    return MD5Sum< ::dji_sdk::StereoDepthSubscription >::value();
  }
  static const char* value(const ::dji_sdk::StereoDepthSubscriptionRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::dji_sdk::StereoDepthSubscriptionRequest> should match 
// service_traits::DataType< ::dji_sdk::StereoDepthSubscription > 
template<>
struct DataType< ::dji_sdk::StereoDepthSubscriptionRequest>
{
  static const char* value()
  {
    return DataType< ::dji_sdk::StereoDepthSubscription >::value();
  }
  static const char* value(const ::dji_sdk::StereoDepthSubscriptionRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::dji_sdk::StereoDepthSubscriptionResponse> should match 
// service_traits::MD5Sum< ::dji_sdk::StereoDepthSubscription > 
template<>
struct MD5Sum< ::dji_sdk::StereoDepthSubscriptionResponse>
{
  static const char* value()
  {
    return MD5Sum< ::dji_sdk::StereoDepthSubscription >::value();
  }
  static const char* value(const ::dji_sdk::StereoDepthSubscriptionResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::dji_sdk::StereoDepthSubscriptionResponse> should match 
// service_traits::DataType< ::dji_sdk::StereoDepthSubscription > 
template<>
struct DataType< ::dji_sdk::StereoDepthSubscriptionResponse>
{
  static const char* value()
  {
    return DataType< ::dji_sdk::StereoDepthSubscription >::value();
  }
  static const char* value(const ::dji_sdk::StereoDepthSubscriptionResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // DJI_SDK_MESSAGE_STEREODEPTHSUBSCRIPTION_H
