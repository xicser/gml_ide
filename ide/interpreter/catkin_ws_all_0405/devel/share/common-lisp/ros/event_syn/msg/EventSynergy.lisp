; Auto-generated. Do not edit!


(cl:in-package event_syn-msg)


;//! \htmlinclude EventSynergy.msg.html

(cl:defclass <EventSynergy> (roslisp-msg-protocol:ros-message)
  ((base
    :reader base
    :initarg :base
    :type event_syn-msg:EventBase
    :initform (cl:make-instance 'event_syn-msg:EventBase))
   (synergyType
    :reader synergyType
    :initarg :synergyType
    :type cl:string
    :initform "")
   (synergyEvent
    :reader synergyEvent
    :initarg :synergyEvent
    :type cl:string
    :initform "")
   (synergyObject
    :reader synergyObject
    :initarg :synergyObject
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element "")))
)

(cl:defclass EventSynergy (<EventSynergy>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <EventSynergy>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'EventSynergy)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name event_syn-msg:<EventSynergy> is deprecated: use event_syn-msg:EventSynergy instead.")))

(cl:ensure-generic-function 'base-val :lambda-list '(m))
(cl:defmethod base-val ((m <EventSynergy>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_syn-msg:base-val is deprecated.  Use event_syn-msg:base instead.")
  (base m))

(cl:ensure-generic-function 'synergyType-val :lambda-list '(m))
(cl:defmethod synergyType-val ((m <EventSynergy>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_syn-msg:synergyType-val is deprecated.  Use event_syn-msg:synergyType instead.")
  (synergyType m))

(cl:ensure-generic-function 'synergyEvent-val :lambda-list '(m))
(cl:defmethod synergyEvent-val ((m <EventSynergy>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_syn-msg:synergyEvent-val is deprecated.  Use event_syn-msg:synergyEvent instead.")
  (synergyEvent m))

(cl:ensure-generic-function 'synergyObject-val :lambda-list '(m))
(cl:defmethod synergyObject-val ((m <EventSynergy>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_syn-msg:synergyObject-val is deprecated.  Use event_syn-msg:synergyObject instead.")
  (synergyObject m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EventSynergy>) ostream)
  "Serializes a message object of type '<EventSynergy>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'base) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'synergyType))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'synergyType))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'synergyEvent))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'synergyEvent))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'synergyObject))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((__ros_str_len (cl:length ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) ele))
   (cl:slot-value msg 'synergyObject))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <EventSynergy>) istream)
  "Deserializes a message object of type '<EventSynergy>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'base) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'synergyType) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'synergyType) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'synergyEvent) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'synergyEvent) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'synergyObject) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'synergyObject)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:aref vals i) __ros_str_idx) (cl:code-char (cl:read-byte istream))))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<EventSynergy>)))
  "Returns string type for a message object of type '<EventSynergy>"
  "event_syn/EventSynergy")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EventSynergy)))
  "Returns string type for a message object of type 'EventSynergy"
  "event_syn/EventSynergy")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EventSynergy>)))
  "Returns md5sum for a message object of type '<EventSynergy>"
  "8a522657f44ca2b2a7a97cab253c1c6b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EventSynergy)))
  "Returns md5sum for a message object of type 'EventSynergy"
  "8a522657f44ca2b2a7a97cab253c1c6b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EventSynergy>)))
  "Returns full string definition for message of type '<EventSynergy>"
  (cl:format cl:nil "event_syn/EventBase base~%string synergyType~%string synergyEvent~%string[] synergyObject~%================================================================================~%MSG: event_syn/EventBase~%int64 ID~%string source~%time begintime~%time endtime~%geometry_msgs/Point startPoint~%geometry_msgs/Point endPoint~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EventSynergy)))
  "Returns full string definition for message of type 'EventSynergy"
  (cl:format cl:nil "event_syn/EventBase base~%string synergyType~%string synergyEvent~%string[] synergyObject~%================================================================================~%MSG: event_syn/EventBase~%int64 ID~%string source~%time begintime~%time endtime~%geometry_msgs/Point startPoint~%geometry_msgs/Point endPoint~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EventSynergy>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'base))
     4 (cl:length (cl:slot-value msg 'synergyType))
     4 (cl:length (cl:slot-value msg 'synergyEvent))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'synergyObject) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EventSynergy>))
  "Converts a ROS message object to a list"
  (cl:list 'EventSynergy
    (cl:cons ':base (base msg))
    (cl:cons ':synergyType (synergyType msg))
    (cl:cons ':synergyEvent (synergyEvent msg))
    (cl:cons ':synergyObject (synergyObject msg))
))
