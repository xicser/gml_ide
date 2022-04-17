; Auto-generated. Do not edit!


(cl:in-package event_comm-msg)


;//! \htmlinclude EventBase.msg.html

(cl:defclass <EventBase> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (eventID
    :reader eventID
    :initarg :eventID
    :type cl:string
    :initform "")
   (source
    :reader source
    :initarg :source
    :type cl:string
    :initform "")
   (begintime
    :reader begintime
    :initarg :begintime
    :type cl:real
    :initform 0)
   (endtime
    :reader endtime
    :initarg :endtime
    :type cl:real
    :initform 0)
   (startPoint
    :reader startPoint
    :initarg :startPoint
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (endPoint
    :reader endPoint
    :initarg :endPoint
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point)))
)

(cl:defclass EventBase (<EventBase>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <EventBase>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'EventBase)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name event_comm-msg:<EventBase> is deprecated: use event_comm-msg:EventBase instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <EventBase>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_comm-msg:header-val is deprecated.  Use event_comm-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'eventID-val :lambda-list '(m))
(cl:defmethod eventID-val ((m <EventBase>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_comm-msg:eventID-val is deprecated.  Use event_comm-msg:eventID instead.")
  (eventID m))

(cl:ensure-generic-function 'source-val :lambda-list '(m))
(cl:defmethod source-val ((m <EventBase>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_comm-msg:source-val is deprecated.  Use event_comm-msg:source instead.")
  (source m))

(cl:ensure-generic-function 'begintime-val :lambda-list '(m))
(cl:defmethod begintime-val ((m <EventBase>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_comm-msg:begintime-val is deprecated.  Use event_comm-msg:begintime instead.")
  (begintime m))

(cl:ensure-generic-function 'endtime-val :lambda-list '(m))
(cl:defmethod endtime-val ((m <EventBase>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_comm-msg:endtime-val is deprecated.  Use event_comm-msg:endtime instead.")
  (endtime m))

(cl:ensure-generic-function 'startPoint-val :lambda-list '(m))
(cl:defmethod startPoint-val ((m <EventBase>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_comm-msg:startPoint-val is deprecated.  Use event_comm-msg:startPoint instead.")
  (startPoint m))

(cl:ensure-generic-function 'endPoint-val :lambda-list '(m))
(cl:defmethod endPoint-val ((m <EventBase>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_comm-msg:endPoint-val is deprecated.  Use event_comm-msg:endPoint instead.")
  (endPoint m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EventBase>) ostream)
  "Serializes a message object of type '<EventBase>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'eventID))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'eventID))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'source))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'source))
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'begintime)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'begintime) (cl:floor (cl:slot-value msg 'begintime)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'endtime)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'endtime) (cl:floor (cl:slot-value msg 'endtime)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'startPoint) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'endPoint) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <EventBase>) istream)
  "Deserializes a message object of type '<EventBase>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'eventID) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'eventID) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'source) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'source) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'begintime) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'endtime) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'startPoint) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'endPoint) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<EventBase>)))
  "Returns string type for a message object of type '<EventBase>"
  "event_comm/EventBase")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EventBase)))
  "Returns string type for a message object of type 'EventBase"
  "event_comm/EventBase")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EventBase>)))
  "Returns md5sum for a message object of type '<EventBase>"
  "d88ecb03d6ed3e38611b950e30397c7a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EventBase)))
  "Returns md5sum for a message object of type 'EventBase"
  "d88ecb03d6ed3e38611b950e30397c7a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EventBase>)))
  "Returns full string definition for message of type '<EventBase>"
  (cl:format cl:nil "std_msgs/Header header~%string eventID~%string source~%time begintime~%time endtime~%geometry_msgs/Point startPoint~%geometry_msgs/Point endPoint~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EventBase)))
  "Returns full string definition for message of type 'EventBase"
  (cl:format cl:nil "std_msgs/Header header~%string eventID~%string source~%time begintime~%time endtime~%geometry_msgs/Point startPoint~%geometry_msgs/Point endPoint~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EventBase>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:length (cl:slot-value msg 'eventID))
     4 (cl:length (cl:slot-value msg 'source))
     8
     8
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'startPoint))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'endPoint))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EventBase>))
  "Converts a ROS message object to a list"
  (cl:list 'EventBase
    (cl:cons ':header (header msg))
    (cl:cons ':eventID (eventID msg))
    (cl:cons ':source (source msg))
    (cl:cons ':begintime (begintime msg))
    (cl:cons ':endtime (endtime msg))
    (cl:cons ':startPoint (startPoint msg))
    (cl:cons ':endPoint (endPoint msg))
))
