; Auto-generated. Do not edit!


(cl:in-package osflock_test-msg)


;//! \htmlinclude IDQP.msg.html

(cl:defclass <IDQP> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type cl:fixnum
    :initform 0)
   (q
    :reader q
    :initarg :q
    :type geometry_msgs-msg:Point32
    :initform (cl:make-instance 'geometry_msgs-msg:Point32))
   (p
    :reader p
    :initarg :p
    :type geometry_msgs-msg:Point32
    :initform (cl:make-instance 'geometry_msgs-msg:Point32)))
)

(cl:defclass IDQP (<IDQP>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <IDQP>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'IDQP)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name osflock_test-msg:<IDQP> is deprecated: use osflock_test-msg:IDQP instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <IDQP>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader osflock_test-msg:id-val is deprecated.  Use osflock_test-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'q-val :lambda-list '(m))
(cl:defmethod q-val ((m <IDQP>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader osflock_test-msg:q-val is deprecated.  Use osflock_test-msg:q instead.")
  (q m))

(cl:ensure-generic-function 'p-val :lambda-list '(m))
(cl:defmethod p-val ((m <IDQP>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader osflock_test-msg:p-val is deprecated.  Use osflock_test-msg:p instead.")
  (p m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <IDQP>) ostream)
  "Serializes a message object of type '<IDQP>"
  (cl:let* ((signed (cl:slot-value msg 'id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'q) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'p) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <IDQP>) istream)
  "Deserializes a message object of type '<IDQP>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'q) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'p) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<IDQP>)))
  "Returns string type for a message object of type '<IDQP>"
  "osflock_test/IDQP")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'IDQP)))
  "Returns string type for a message object of type 'IDQP"
  "osflock_test/IDQP")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<IDQP>)))
  "Returns md5sum for a message object of type '<IDQP>"
  "de73cd8cc01a3a407b0a10781a1dd6a4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'IDQP)))
  "Returns md5sum for a message object of type 'IDQP"
  "de73cd8cc01a3a407b0a10781a1dd6a4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<IDQP>)))
  "Returns full string definition for message of type '<IDQP>"
  (cl:format cl:nil "int8 id # agent id~%geometry_msgs/Point32 q # agent position~%geometry_msgs/Point32 p # agent velocity~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'IDQP)))
  "Returns full string definition for message of type 'IDQP"
  (cl:format cl:nil "int8 id # agent id~%geometry_msgs/Point32 q # agent position~%geometry_msgs/Point32 p # agent velocity~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <IDQP>))
  (cl:+ 0
     1
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'q))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'p))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <IDQP>))
  "Converts a ROS message object to a list"
  (cl:list 'IDQP
    (cl:cons ':id (id msg))
    (cl:cons ':q (q msg))
    (cl:cons ':p (p msg))
))
