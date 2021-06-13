; Auto-generated. Do not edit!


(cl:in-package event_syn-msg)


;//! \htmlinclude EventBase.msg.html

(cl:defclass <EventBase> (roslisp-msg-protocol:ros-message)
  ((ID
    :reader ID
    :initarg :ID
    :type cl:integer
    :initform 0)
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
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name event_syn-msg:<EventBase> is deprecated: use event_syn-msg:EventBase instead.")))

(cl:ensure-generic-function 'ID-val :lambda-list '(m))
(cl:defmethod ID-val ((m <EventBase>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_syn-msg:ID-val is deprecated.  Use event_syn-msg:ID instead.")
  (ID m))

(cl:ensure-generic-function 'source-val :lambda-list '(m))
(cl:defmethod source-val ((m <EventBase>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_syn-msg:source-val is deprecated.  Use event_syn-msg:source instead.")
  (source m))

(cl:ensure-generic-function 'begintime-val :lambda-list '(m))
(cl:defmethod begintime-val ((m <EventBase>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_syn-msg:begintime-val is deprecated.  Use event_syn-msg:begintime instead.")
  (begintime m))

(cl:ensure-generic-function 'endtime-val :lambda-list '(m))
(cl:defmethod endtime-val ((m <EventBase>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_syn-msg:endtime-val is deprecated.  Use event_syn-msg:endtime instead.")
  (endtime m))

(cl:ensure-generic-function 'startPoint-val :lambda-list '(m))
(cl:defmethod startPoint-val ((m <EventBase>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_syn-msg:startPoint-val is deprecated.  Use event_syn-msg:startPoint instead.")
  (startPoint m))

(cl:ensure-generic-function 'endPoint-val :lambda-list '(m))
(cl:defmethod endPoint-val ((m <EventBase>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_syn-msg:endPoint-val is deprecated.  Use event_syn-msg:endPoint instead.")
  (endPoint m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EventBase>) ostream)
  "Serializes a message object of type '<EventBase>"
  (cl:let* ((signed (cl:slot-value msg 'ID)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
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
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ID) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
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
  "event_syn/EventBase")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EventBase)))
  "Returns string type for a message object of type 'EventBase"
  "event_syn/EventBase")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EventBase>)))
  "Returns md5sum for a message object of type '<EventBase>"
  "0fd9c6075ee389ae992199348b844526")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EventBase)))
  "Returns md5sum for a message object of type 'EventBase"
  "0fd9c6075ee389ae992199348b844526")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EventBase>)))
  "Returns full string definition for message of type '<EventBase>"
  (cl:format cl:nil "int64 ID~%string source~%time begintime~%time endtime~%geometry_msgs/Point startPoint~%geometry_msgs/Point endPoint~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EventBase)))
  "Returns full string definition for message of type 'EventBase"
  (cl:format cl:nil "int64 ID~%string source~%time begintime~%time endtime~%geometry_msgs/Point startPoint~%geometry_msgs/Point endPoint~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EventBase>))
  (cl:+ 0
     8
     4 (cl:length (cl:slot-value msg 'source))
     8
     8
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'startPoint))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'endPoint))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EventBase>))
  "Converts a ROS message object to a list"
  (cl:list 'EventBase
    (cl:cons ':ID (ID msg))
    (cl:cons ':source (source msg))
    (cl:cons ':begintime (begintime msg))
    (cl:cons ':endtime (endtime msg))
    (cl:cons ':startPoint (startPoint msg))
    (cl:cons ':endPoint (endPoint msg))
))
