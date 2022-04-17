; Auto-generated. Do not edit!


(cl:in-package event_comm-msg)


;//! \htmlinclude EventCollaborative.msg.html

(cl:defclass <EventCollaborative> (roslisp-msg-protocol:ros-message)
  ((base
    :reader base
    :initarg :base
    :type event_comm-msg:EventBase
    :initform (cl:make-instance 'event_comm-msg:EventBase))
   (collaborativeType
    :reader collaborativeType
    :initarg :collaborativeType
    :type cl:string
    :initform "")
   (collaborativeEvent
    :reader collaborativeEvent
    :initarg :collaborativeEvent
    :type cl:string
    :initform "")
   (collaborativeObject
    :reader collaborativeObject
    :initarg :collaborativeObject
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element "")))
)

(cl:defclass EventCollaborative (<EventCollaborative>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <EventCollaborative>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'EventCollaborative)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name event_comm-msg:<EventCollaborative> is deprecated: use event_comm-msg:EventCollaborative instead.")))

(cl:ensure-generic-function 'base-val :lambda-list '(m))
(cl:defmethod base-val ((m <EventCollaborative>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_comm-msg:base-val is deprecated.  Use event_comm-msg:base instead.")
  (base m))

(cl:ensure-generic-function 'collaborativeType-val :lambda-list '(m))
(cl:defmethod collaborativeType-val ((m <EventCollaborative>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_comm-msg:collaborativeType-val is deprecated.  Use event_comm-msg:collaborativeType instead.")
  (collaborativeType m))

(cl:ensure-generic-function 'collaborativeEvent-val :lambda-list '(m))
(cl:defmethod collaborativeEvent-val ((m <EventCollaborative>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_comm-msg:collaborativeEvent-val is deprecated.  Use event_comm-msg:collaborativeEvent instead.")
  (collaborativeEvent m))

(cl:ensure-generic-function 'collaborativeObject-val :lambda-list '(m))
(cl:defmethod collaborativeObject-val ((m <EventCollaborative>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_comm-msg:collaborativeObject-val is deprecated.  Use event_comm-msg:collaborativeObject instead.")
  (collaborativeObject m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EventCollaborative>) ostream)
  "Serializes a message object of type '<EventCollaborative>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'base) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'collaborativeType))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'collaborativeType))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'collaborativeEvent))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'collaborativeEvent))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'collaborativeObject))))
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
   (cl:slot-value msg 'collaborativeObject))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <EventCollaborative>) istream)
  "Deserializes a message object of type '<EventCollaborative>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'base) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'collaborativeType) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'collaborativeType) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'collaborativeEvent) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'collaborativeEvent) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'collaborativeObject) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'collaborativeObject)))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<EventCollaborative>)))
  "Returns string type for a message object of type '<EventCollaborative>"
  "event_comm/EventCollaborative")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EventCollaborative)))
  "Returns string type for a message object of type 'EventCollaborative"
  "event_comm/EventCollaborative")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EventCollaborative>)))
  "Returns md5sum for a message object of type '<EventCollaborative>"
  "d067c2bef3be9d576d17bc244d1ee209")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EventCollaborative)))
  "Returns md5sum for a message object of type 'EventCollaborative"
  "d067c2bef3be9d576d17bc244d1ee209")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EventCollaborative>)))
  "Returns full string definition for message of type '<EventCollaborative>"
  (cl:format cl:nil "event_comm/EventBase base~%string collaborativeType~%string collaborativeEvent~%string[] collaborativeObject~%================================================================================~%MSG: event_comm/EventBase~%std_msgs/Header header~%string eventID~%string source~%time begintime~%time endtime~%geometry_msgs/Point startPoint~%geometry_msgs/Point endPoint~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EventCollaborative)))
  "Returns full string definition for message of type 'EventCollaborative"
  (cl:format cl:nil "event_comm/EventBase base~%string collaborativeType~%string collaborativeEvent~%string[] collaborativeObject~%================================================================================~%MSG: event_comm/EventBase~%std_msgs/Header header~%string eventID~%string source~%time begintime~%time endtime~%geometry_msgs/Point startPoint~%geometry_msgs/Point endPoint~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EventCollaborative>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'base))
     4 (cl:length (cl:slot-value msg 'collaborativeType))
     4 (cl:length (cl:slot-value msg 'collaborativeEvent))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'collaborativeObject) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EventCollaborative>))
  "Converts a ROS message object to a list"
  (cl:list 'EventCollaborative
    (cl:cons ':base (base msg))
    (cl:cons ':collaborativeType (collaborativeType msg))
    (cl:cons ':collaborativeEvent (collaborativeEvent msg))
    (cl:cons ':collaborativeObject (collaborativeObject msg))
))
