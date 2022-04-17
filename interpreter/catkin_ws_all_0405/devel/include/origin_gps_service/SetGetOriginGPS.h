// Generated by gencpp from file origin_gps_service/SetGetOriginGPS.msg
// DO NOT EDIT!


#ifndef ORIGIN_GPS_SERVICE_MESSAGE_SETGETORIGINGPS_H
#define ORIGIN_GPS_SERVICE_MESSAGE_SETGETORIGINGPS_H

#include <ros/service_traits.h>


#include <origin_gps_service/SetGetOriginGPSRequest.h>
#include <origin_gps_service/SetGetOriginGPSResponse.h>


namespace origin_gps_service
{

struct SetGetOriginGPS
{

typedef SetGetOriginGPSRequest Request;
typedef SetGetOriginGPSResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetGetOriginGPS
} // namespace origin_gps_service


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::origin_gps_service::SetGetOriginGPS > {
  static const char* value()
  {
    return "76078d86916adec6d06d1ecf85305b35";
  }

  static const char* value(const ::origin_gps_service::SetGetOriginGPS&) { return value(); }
};

template<>
struct DataType< ::origin_gps_service::SetGetOriginGPS > {
  static const char* value()
  {
    return "origin_gps_service/SetGetOriginGPS";
  }

  static const char* value(const ::origin_gps_service::SetGetOriginGPS&) { return value(); }
};


// service_traits::MD5Sum< ::origin_gps_service::SetGetOriginGPSRequest> should match 
// service_traits::MD5Sum< ::origin_gps_service::SetGetOriginGPS > 
template<>
struct MD5Sum< ::origin_gps_service::SetGetOriginGPSRequest>
{
  static const char* value()
  {
    return MD5Sum< ::origin_gps_service::SetGetOriginGPS >::value();
  }
  static const char* value(const ::origin_gps_service::SetGetOriginGPSRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::origin_gps_service::SetGetOriginGPSRequest> should match 
// service_traits::DataType< ::origin_gps_service::SetGetOriginGPS > 
template<>
struct DataType< ::origin_gps_service::SetGetOriginGPSRequest>
{
  static const char* value()
  {
    return DataType< ::origin_gps_service::SetGetOriginGPS >::value();
  }
  static const char* value(const ::origin_gps_service::SetGetOriginGPSRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::origin_gps_service::SetGetOriginGPSResponse> should match 
// service_traits::MD5Sum< ::origin_gps_service::SetGetOriginGPS > 
template<>
struct MD5Sum< ::origin_gps_service::SetGetOriginGPSResponse>
{
  static const char* value()
  {
    return MD5Sum< ::origin_gps_service::SetGetOriginGPS >::value();
  }
  static const char* value(const ::origin_gps_service::SetGetOriginGPSResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::origin_gps_service::SetGetOriginGPSResponse> should match 
// service_traits::DataType< ::origin_gps_service::SetGetOriginGPS > 
template<>
struct DataType< ::origin_gps_service::SetGetOriginGPSResponse>
{
  static const char* value()
  {
    return DataType< ::origin_gps_service::SetGetOriginGPS >::value();
  }
  static const char* value(const ::origin_gps_service::SetGetOriginGPSResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ORIGIN_GPS_SERVICE_MESSAGE_SETGETORIGINGPS_H