; Auto-generated. Do not edit!


(cl:in-package origin_gps_service-srv)


;//! \htmlinclude SetGetOriginGPS-request.msg.html

(cl:defclass <SetGetOriginGPS-request> (roslisp-msg-protocol:ros-message)
  ((home_gps
    :reader home_gps
    :initarg :home_gps
    :type sensor_msgs-msg:NavSatFix
    :initform (cl:make-instance 'sensor_msgs-msg:NavSatFix)))
)

(cl:defclass SetGetOriginGPS-request (<SetGetOriginGPS-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetGetOriginGPS-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetGetOriginGPS-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name origin_gps_service-srv:<SetGetOriginGPS-request> is deprecated: use origin_gps_service-srv:SetGetOriginGPS-request instead.")))

(cl:ensure-generic-function 'home_gps-val :lambda-list '(m))
(cl:defmethod home_gps-val ((m <SetGetOriginGPS-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader origin_gps_service-srv:home_gps-val is deprecated.  Use origin_gps_service-srv:home_gps instead.")
  (home_gps m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetGetOriginGPS-request>) ostream)
  "Serializes a message object of type '<SetGetOriginGPS-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'home_gps) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetGetOriginGPS-request>) istream)
  "Deserializes a message object of type '<SetGetOriginGPS-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'home_gps) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetGetOriginGPS-request>)))
  "Returns string type for a service object of type '<SetGetOriginGPS-request>"
  "origin_gps_service/SetGetOriginGPSRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetGetOriginGPS-request)))
  "Returns string type for a service object of type 'SetGetOriginGPS-request"
  "origin_gps_service/SetGetOriginGPSRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetGetOriginGPS-request>)))
  "Returns md5sum for a message object of type '<SetGetOriginGPS-request>"
  "76078d86916adec6d06d1ecf85305b35")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetGetOriginGPS-request)))
  "Returns md5sum for a message object of type 'SetGetOriginGPS-request"
  "76078d86916adec6d06d1ecf85305b35")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetGetOriginGPS-request>)))
  "Returns full string definition for message of type '<SetGetOriginGPS-request>"
  (cl:format cl:nil "sensor_msgs/NavSatFix home_gps~%~%================================================================================~%MSG: sensor_msgs/NavSatFix~%# Navigation Satellite fix for any Global Navigation Satellite System~%#~%# Specified using the WGS 84 reference ellipsoid~%~%# header.stamp specifies the ROS time for this measurement (the~%#        corresponding satellite time may be reported using the~%#        sensor_msgs/TimeReference message).~%#~%# header.frame_id is the frame of reference reported by the satellite~%#        receiver, usually the location of the antenna.  This is a~%#        Euclidean frame relative to the vehicle, not a reference~%#        ellipsoid.~%Header header~%~%# satellite fix status information~%NavSatStatus status~%~%# Latitude [degrees]. Positive is north of equator; negative is south.~%float64 latitude~%~%# Longitude [degrees]. Positive is east of prime meridian; negative is west.~%float64 longitude~%~%# Altitude [m]. Positive is above the WGS 84 ellipsoid~%# (quiet NaN if no altitude is available).~%float64 altitude~%~%# Position covariance [m^2] defined relative to a tangential plane~%# through the reported position. The components are East, North, and~%# Up (ENU), in row-major order.~%#~%# Beware: this coordinate system exhibits singularities at the poles.~%~%float64[9] position_covariance~%~%# If the covariance of the fix is known, fill it in completely. If the~%# GPS receiver provides the variance of each measurement, put them~%# along the diagonal. If only Dilution of Precision is available,~%# estimate an approximate covariance from that.~%~%uint8 COVARIANCE_TYPE_UNKNOWN = 0~%uint8 COVARIANCE_TYPE_APPROXIMATED = 1~%uint8 COVARIANCE_TYPE_DIAGONAL_KNOWN = 2~%uint8 COVARIANCE_TYPE_KNOWN = 3~%~%uint8 position_covariance_type~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: sensor_msgs/NavSatStatus~%# Navigation Satellite fix status for any Global Navigation Satellite System~%~%# Whether to output an augmented fix is determined by both the fix~%# type and the last time differential corrections were received.  A~%# fix is valid when status >= STATUS_FIX.~%~%int8 STATUS_NO_FIX =  -1        # unable to fix position~%int8 STATUS_FIX =      0        # unaugmented fix~%int8 STATUS_SBAS_FIX = 1        # with satellite-based augmentation~%int8 STATUS_GBAS_FIX = 2        # with ground-based augmentation~%~%int8 status~%~%# Bits defining which Global Navigation Satellite System signals were~%# used by the receiver.~%~%uint16 SERVICE_GPS =     1~%uint16 SERVICE_GLONASS = 2~%uint16 SERVICE_COMPASS = 4      # includes BeiDou.~%uint16 SERVICE_GALILEO = 8~%~%uint16 service~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetGetOriginGPS-request)))
  "Returns full string definition for message of type 'SetGetOriginGPS-request"
  (cl:format cl:nil "sensor_msgs/NavSatFix home_gps~%~%================================================================================~%MSG: sensor_msgs/NavSatFix~%# Navigation Satellite fix for any Global Navigation Satellite System~%#~%# Specified using the WGS 84 reference ellipsoid~%~%# header.stamp specifies the ROS time for this measurement (the~%#        corresponding satellite time may be reported using the~%#        sensor_msgs/TimeReference message).~%#~%# header.frame_id is the frame of reference reported by the satellite~%#        receiver, usually the location of the antenna.  This is a~%#        Euclidean frame relative to the vehicle, not a reference~%#        ellipsoid.~%Header header~%~%# satellite fix status information~%NavSatStatus status~%~%# Latitude [degrees]. Positive is north of equator; negative is south.~%float64 latitude~%~%# Longitude [degrees]. Positive is east of prime meridian; negative is west.~%float64 longitude~%~%# Altitude [m]. Positive is above the WGS 84 ellipsoid~%# (quiet NaN if no altitude is available).~%float64 altitude~%~%# Position covariance [m^2] defined relative to a tangential plane~%# through the reported position. The components are East, North, and~%# Up (ENU), in row-major order.~%#~%# Beware: this coordinate system exhibits singularities at the poles.~%~%float64[9] position_covariance~%~%# If the covariance of the fix is known, fill it in completely. If the~%# GPS receiver provides the variance of each measurement, put them~%# along the diagonal. If only Dilution of Precision is available,~%# estimate an approximate covariance from that.~%~%uint8 COVARIANCE_TYPE_UNKNOWN = 0~%uint8 COVARIANCE_TYPE_APPROXIMATED = 1~%uint8 COVARIANCE_TYPE_DIAGONAL_KNOWN = 2~%uint8 COVARIANCE_TYPE_KNOWN = 3~%~%uint8 position_covariance_type~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: sensor_msgs/NavSatStatus~%# Navigation Satellite fix status for any Global Navigation Satellite System~%~%# Whether to output an augmented fix is determined by both the fix~%# type and the last time differential corrections were received.  A~%# fix is valid when status >= STATUS_FIX.~%~%int8 STATUS_NO_FIX =  -1        # unable to fix position~%int8 STATUS_FIX =      0        # unaugmented fix~%int8 STATUS_SBAS_FIX = 1        # with satellite-based augmentation~%int8 STATUS_GBAS_FIX = 2        # with ground-based augmentation~%~%int8 status~%~%# Bits defining which Global Navigation Satellite System signals were~%# used by the receiver.~%~%uint16 SERVICE_GPS =     1~%uint16 SERVICE_GLONASS = 2~%uint16 SERVICE_COMPASS = 4      # includes BeiDou.~%uint16 SERVICE_GALILEO = 8~%~%uint16 service~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetGetOriginGPS-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'home_gps))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetGetOriginGPS-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SetGetOriginGPS-request
    (cl:cons ':home_gps (home_gps msg))
))
;//! \htmlinclude SetGetOriginGPS-response.msg.html

(cl:defclass <SetGetOriginGPS-response> (roslisp-msg-protocol:ros-message)
  ((origin_gps
    :reader origin_gps
    :initarg :origin_gps
    :type sensor_msgs-msg:NavSatFix
    :initform (cl:make-instance 'sensor_msgs-msg:NavSatFix)))
)

(cl:defclass SetGetOriginGPS-response (<SetGetOriginGPS-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetGetOriginGPS-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetGetOriginGPS-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name origin_gps_service-srv:<SetGetOriginGPS-response> is deprecated: use origin_gps_service-srv:SetGetOriginGPS-response instead.")))

(cl:ensure-generic-function 'origin_gps-val :lambda-list '(m))
(cl:defmethod origin_gps-val ((m <SetGetOriginGPS-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader origin_gps_service-srv:origin_gps-val is deprecated.  Use origin_gps_service-srv:origin_gps instead.")
  (origin_gps m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetGetOriginGPS-response>) ostream)
  "Serializes a message object of type '<SetGetOriginGPS-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'origin_gps) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetGetOriginGPS-response>) istream)
  "Deserializes a message object of type '<SetGetOriginGPS-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'origin_gps) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetGetOriginGPS-response>)))
  "Returns string type for a service object of type '<SetGetOriginGPS-response>"
  "origin_gps_service/SetGetOriginGPSResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetGetOriginGPS-response)))
  "Returns string type for a service object of type 'SetGetOriginGPS-response"
  "origin_gps_service/SetGetOriginGPSResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetGetOriginGPS-response>)))
  "Returns md5sum for a message object of type '<SetGetOriginGPS-response>"
  "76078d86916adec6d06d1ecf85305b35")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetGetOriginGPS-response)))
  "Returns md5sum for a message object of type 'SetGetOriginGPS-response"
  "76078d86916adec6d06d1ecf85305b35")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetGetOriginGPS-response>)))
  "Returns full string definition for message of type '<SetGetOriginGPS-response>"
  (cl:format cl:nil "sensor_msgs/NavSatFix origin_gps~%~%================================================================================~%MSG: sensor_msgs/NavSatFix~%# Navigation Satellite fix for any Global Navigation Satellite System~%#~%# Specified using the WGS 84 reference ellipsoid~%~%# header.stamp specifies the ROS time for this measurement (the~%#        corresponding satellite time may be reported using the~%#        sensor_msgs/TimeReference message).~%#~%# header.frame_id is the frame of reference reported by the satellite~%#        receiver, usually the location of the antenna.  This is a~%#        Euclidean frame relative to the vehicle, not a reference~%#        ellipsoid.~%Header header~%~%# satellite fix status information~%NavSatStatus status~%~%# Latitude [degrees]. Positive is north of equator; negative is south.~%float64 latitude~%~%# Longitude [degrees]. Positive is east of prime meridian; negative is west.~%float64 longitude~%~%# Altitude [m]. Positive is above the WGS 84 ellipsoid~%# (quiet NaN if no altitude is available).~%float64 altitude~%~%# Position covariance [m^2] defined relative to a tangential plane~%# through the reported position. The components are East, North, and~%# Up (ENU), in row-major order.~%#~%# Beware: this coordinate system exhibits singularities at the poles.~%~%float64[9] position_covariance~%~%# If the covariance of the fix is known, fill it in completely. If the~%# GPS receiver provides the variance of each measurement, put them~%# along the diagonal. If only Dilution of Precision is available,~%# estimate an approximate covariance from that.~%~%uint8 COVARIANCE_TYPE_UNKNOWN = 0~%uint8 COVARIANCE_TYPE_APPROXIMATED = 1~%uint8 COVARIANCE_TYPE_DIAGONAL_KNOWN = 2~%uint8 COVARIANCE_TYPE_KNOWN = 3~%~%uint8 position_covariance_type~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: sensor_msgs/NavSatStatus~%# Navigation Satellite fix status for any Global Navigation Satellite System~%~%# Whether to output an augmented fix is determined by both the fix~%# type and the last time differential corrections were received.  A~%# fix is valid when status >= STATUS_FIX.~%~%int8 STATUS_NO_FIX =  -1        # unable to fix position~%int8 STATUS_FIX =      0        # unaugmented fix~%int8 STATUS_SBAS_FIX = 1        # with satellite-based augmentation~%int8 STATUS_GBAS_FIX = 2        # with ground-based augmentation~%~%int8 status~%~%# Bits defining which Global Navigation Satellite System signals were~%# used by the receiver.~%~%uint16 SERVICE_GPS =     1~%uint16 SERVICE_GLONASS = 2~%uint16 SERVICE_COMPASS = 4      # includes BeiDou.~%uint16 SERVICE_GALILEO = 8~%~%uint16 service~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetGetOriginGPS-response)))
  "Returns full string definition for message of type 'SetGetOriginGPS-response"
  (cl:format cl:nil "sensor_msgs/NavSatFix origin_gps~%~%================================================================================~%MSG: sensor_msgs/NavSatFix~%# Navigation Satellite fix for any Global Navigation Satellite System~%#~%# Specified using the WGS 84 reference ellipsoid~%~%# header.stamp specifies the ROS time for this measurement (the~%#        corresponding satellite time may be reported using the~%#        sensor_msgs/TimeReference message).~%#~%# header.frame_id is the frame of reference reported by the satellite~%#        receiver, usually the location of the antenna.  This is a~%#        Euclidean frame relative to the vehicle, not a reference~%#        ellipsoid.~%Header header~%~%# satellite fix status information~%NavSatStatus status~%~%# Latitude [degrees]. Positive is north of equator; negative is south.~%float64 latitude~%~%# Longitude [degrees]. Positive is east of prime meridian; negative is west.~%float64 longitude~%~%# Altitude [m]. Positive is above the WGS 84 ellipsoid~%# (quiet NaN if no altitude is available).~%float64 altitude~%~%# Position covariance [m^2] defined relative to a tangential plane~%# through the reported position. The components are East, North, and~%# Up (ENU), in row-major order.~%#~%# Beware: this coordinate system exhibits singularities at the poles.~%~%float64[9] position_covariance~%~%# If the covariance of the fix is known, fill it in completely. If the~%# GPS receiver provides the variance of each measurement, put them~%# along the diagonal. If only Dilution of Precision is available,~%# estimate an approximate covariance from that.~%~%uint8 COVARIANCE_TYPE_UNKNOWN = 0~%uint8 COVARIANCE_TYPE_APPROXIMATED = 1~%uint8 COVARIANCE_TYPE_DIAGONAL_KNOWN = 2~%uint8 COVARIANCE_TYPE_KNOWN = 3~%~%uint8 position_covariance_type~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: sensor_msgs/NavSatStatus~%# Navigation Satellite fix status for any Global Navigation Satellite System~%~%# Whether to output an augmented fix is determined by both the fix~%# type and the last time differential corrections were received.  A~%# fix is valid when status >= STATUS_FIX.~%~%int8 STATUS_NO_FIX =  -1        # unable to fix position~%int8 STATUS_FIX =      0        # unaugmented fix~%int8 STATUS_SBAS_FIX = 1        # with satellite-based augmentation~%int8 STATUS_GBAS_FIX = 2        # with ground-based augmentation~%~%int8 status~%~%# Bits defining which Global Navigation Satellite System signals were~%# used by the receiver.~%~%uint16 SERVICE_GPS =     1~%uint16 SERVICE_GLONASS = 2~%uint16 SERVICE_COMPASS = 4      # includes BeiDou.~%uint16 SERVICE_GALILEO = 8~%~%uint16 service~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetGetOriginGPS-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'origin_gps))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetGetOriginGPS-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SetGetOriginGPS-response
    (cl:cons ':origin_gps (origin_gps msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SetGetOriginGPS)))
  'SetGetOriginGPS-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SetGetOriginGPS)))
  'SetGetOriginGPS-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetGetOriginGPS)))
  "Returns string type for a service object of type '<SetGetOriginGPS>"
  "origin_gps_service/SetGetOriginGPS")