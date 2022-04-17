; Auto-generated. Do not edit!


(cl:in-package event_comm-msg)


;//! \htmlinclude EventDynamic.msg.html

(cl:defclass <EventDynamic> (roslisp-msg-protocol:ros-message)
  ((base
    :reader base
    :initarg :base
    :type event_comm-msg:EventBase
    :initform (cl:make-instance 'event_comm-msg:EventBase))
   (dynamicEventName
    :reader dynamicEventName
    :initarg :dynamicEventName
    :type cl:string
    :initform "")
   (dynamicType
    :reader dynamicType
    :initarg :dynamicType
    :type cl:string
    :initform "")
   (dynamicInfo
    :reader dynamicInfo
    :initarg :dynamicInfo
    :type cl:string
    :initform ""))
)

(cl:defclass EventDynamic (<EventDynamic>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <EventDynamic>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'EventDynamic)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name event_comm-msg:<EventDynamic> is deprecated: use event_comm-msg:EventDynamic instead.")))

(cl:ensure-generic-function 'base-val :lambda-list '(m))
(cl:defmethod base-val ((m <EventDynamic>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_comm-msg:base-val is deprecated.  Use event_comm-msg:base instead.")
  (base m))

(cl:ensure-generic-function 'dynamicEventName-val :lambda-list '(m))
(cl:defmethod dynamicEventName-val ((m <EventDynamic>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_comm-msg:dynamicEventName-val is deprecated.  Use event_comm-msg:dynamicEventName instead.")
  (dynamicEventName m))

(cl:ensure-generic-function 'dynamicType-val :lambda-list '(m))
(cl:defmethod dynamicType-val ((m <EventDynamic>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_comm-msg:dynamicType-val is deprecated.  Use event_comm-msg:dynamicType instead.")
  (dynamicType m))

(cl:ensure-generic-function 'dynamicInfo-val :lambda-list '(m))
(cl:defmethod dynamicInfo-val ((m <EventDynamic>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_comm-msg:dynamicInfo-val is deprecated.  Use event_comm-msg:dynamicInfo instead.")
  (dynamicInfo m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EventDynamic>) ostream)
  "Serializes a message object of type '<EventDynamic>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'base) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'dynamicEventName))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'dynamicEventName))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'dynamicType))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'dynamicType))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'dynamicInfo))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'dynamicInfo))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <EventDynamic>) istream)
  "Deserializes a message object of type '<EventDynamic>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'base) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'dynamicEventName) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'dynamicEventName) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'dynamicType) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'dynamicType) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'dynamicInfo) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'dynamicInfo) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<EventDynamic>)))
  "Returns string type for a message object of type '<EventDynamic>"
  "event_comm/EventDynamic")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EventDynamic)))
  "Returns string type for a message object of type 'EventDynamic"
  "event_comm/EventDynamic")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EventDynamic>)))
  "Returns md5sum for a message object of type '<EventDynamic>"
  "2ccc20968a7c0d24ca90b858f3122b4b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EventDynamic)))
  "Returns md5sum for a message object of type 'EventDynamic"
  "2ccc20968a7c0d24ca90b858f3122b4b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EventDynamic>)))
  "Returns full string definition for message of type '<EventDynamic>"
  (cl:format cl:nil "event_comm/EventBase base~%string dynamicEventName~%string dynamicType~%string dynamicInfo~%================================================================================~%MSG: event_comm/EventBase~%std_msgs/Header header~%string eventID~%string source~%time begintime~%time endtime~%geometry_msgs/Point startPoint~%geometry_msgs/Point endPoint~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EventDynamic)))
  "Returns full string definition for message of type 'EventDynamic"
  (cl:format cl:nil "event_comm/EventBase base~%string dynamicEventName~%string dynamicType~%string dynamicInfo~%================================================================================~%MSG: event_comm/EventBase~%std_msgs/Header header~%string eventID~%string source~%time begintime~%time endtime~%geometry_msgs/Point startPoint~%geometry_msgs/Point endPoint~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EventDynamic>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'base))
     4 (cl:length (cl:slot-value msg 'dynamicEventName))
     4 (cl:length (cl:slot-value msg 'dynamicType))
     4 (cl:length (cl:slot-value msg 'dynamicInfo))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EventDynamic>))
  "Converts a ROS message object to a list"
  (cl:list 'EventDynamic
    (cl:cons ':base (base msg))
    (cl:cons ':dynamicEventName (dynamicEventName msg))
    (cl:cons ':dynamicType (dynamicType msg))
    (cl:cons ':dynamicInfo (dynamicInfo msg))
))
