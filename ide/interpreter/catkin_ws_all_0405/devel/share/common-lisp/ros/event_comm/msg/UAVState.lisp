; Auto-generated. Do not edit!


(cl:in-package event_comm-msg)


;//! \htmlinclude UAVState.msg.html

(cl:defclass <UAVState> (roslisp-msg-protocol:ros-message)
  ((UAVnum
    :reader UAVnum
    :initarg :UAVnum
    :type cl:integer
    :initform 0)
   (Point
    :reader Point
    :initarg :Point
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point)))
)

(cl:defclass UAVState (<UAVState>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <UAVState>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'UAVState)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name event_comm-msg:<UAVState> is deprecated: use event_comm-msg:UAVState instead.")))

(cl:ensure-generic-function 'UAVnum-val :lambda-list '(m))
(cl:defmethod UAVnum-val ((m <UAVState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_comm-msg:UAVnum-val is deprecated.  Use event_comm-msg:UAVnum instead.")
  (UAVnum m))

(cl:ensure-generic-function 'Point-val :lambda-list '(m))
(cl:defmethod Point-val ((m <UAVState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader event_comm-msg:Point-val is deprecated.  Use event_comm-msg:Point instead.")
  (Point m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <UAVState>) ostream)
  "Serializes a message object of type '<UAVState>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'UAVnum)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'UAVnum)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'UAVnum)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'UAVnum)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'UAVnum)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'UAVnum)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'UAVnum)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'UAVnum)) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Point) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <UAVState>) istream)
  "Deserializes a message object of type '<UAVState>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'UAVnum)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'UAVnum)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'UAVnum)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'UAVnum)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'UAVnum)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'UAVnum)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'UAVnum)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'UAVnum)) (cl:read-byte istream))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Point) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<UAVState>)))
  "Returns string type for a message object of type '<UAVState>"
  "event_comm/UAVState")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'UAVState)))
  "Returns string type for a message object of type 'UAVState"
  "event_comm/UAVState")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<UAVState>)))
  "Returns md5sum for a message object of type '<UAVState>"
  "82010c98432e82a612d456b09f37f399")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'UAVState)))
  "Returns md5sum for a message object of type 'UAVState"
  "82010c98432e82a612d456b09f37f399")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<UAVState>)))
  "Returns full string definition for message of type '<UAVState>"
  (cl:format cl:nil "uint64 UAVnum~%geometry_msgs/Point Point~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'UAVState)))
  "Returns full string definition for message of type 'UAVState"
  (cl:format cl:nil "uint64 UAVnum~%geometry_msgs/Point Point~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <UAVState>))
  (cl:+ 0
     8
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Point))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <UAVState>))
  "Converts a ROS message object to a list"
  (cl:list 'UAVState
    (cl:cons ':UAVnum (UAVnum msg))
    (cl:cons ':Point (Point msg))
))
