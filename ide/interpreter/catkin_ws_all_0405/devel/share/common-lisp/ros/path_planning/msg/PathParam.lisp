; Auto-generated. Do not edit!


(cl:in-package path_planning-msg)


;//! \htmlinclude PathParam.msg.html

(cl:defclass <PathParam> (roslisp-msg-protocol:ros-message)
  ((start
    :reader start
    :initarg :start
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (goal
    :reader goal
    :initarg :goal
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point)))
)

(cl:defclass PathParam (<PathParam>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PathParam>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PathParam)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name path_planning-msg:<PathParam> is deprecated: use path_planning-msg:PathParam instead.")))

(cl:ensure-generic-function 'start-val :lambda-list '(m))
(cl:defmethod start-val ((m <PathParam>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader path_planning-msg:start-val is deprecated.  Use path_planning-msg:start instead.")
  (start m))

(cl:ensure-generic-function 'goal-val :lambda-list '(m))
(cl:defmethod goal-val ((m <PathParam>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader path_planning-msg:goal-val is deprecated.  Use path_planning-msg:goal instead.")
  (goal m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PathParam>) ostream)
  "Serializes a message object of type '<PathParam>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'start) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'goal) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PathParam>) istream)
  "Deserializes a message object of type '<PathParam>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'start) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'goal) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PathParam>)))
  "Returns string type for a message object of type '<PathParam>"
  "path_planning/PathParam")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PathParam)))
  "Returns string type for a message object of type 'PathParam"
  "path_planning/PathParam")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PathParam>)))
  "Returns md5sum for a message object of type '<PathParam>"
  "efcee77d261910bec0163bff1fcbe065")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PathParam)))
  "Returns md5sum for a message object of type 'PathParam"
  "efcee77d261910bec0163bff1fcbe065")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PathParam>)))
  "Returns full string definition for message of type '<PathParam>"
  (cl:format cl:nil "geometry_msgs/Point start~%geometry_msgs/Point goal~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PathParam)))
  "Returns full string definition for message of type 'PathParam"
  (cl:format cl:nil "geometry_msgs/Point start~%geometry_msgs/Point goal~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PathParam>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'start))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'goal))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PathParam>))
  "Converts a ROS message object to a list"
  (cl:list 'PathParam
    (cl:cons ':start (start msg))
    (cl:cons ':goal (goal msg))
))
