; Auto-generated. Do not edit!


(cl:in-package path_planning-msg)


;//! \htmlinclude PathResult.msg.html

(cl:defclass <PathResult> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type (cl:vector geometry_msgs-msg:Point)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Point :initial-element (cl:make-instance 'geometry_msgs-msg:Point))))
)

(cl:defclass PathResult (<PathResult>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PathResult>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PathResult)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name path_planning-msg:<PathResult> is deprecated: use path_planning-msg:PathResult instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <PathResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader path_planning-msg:result-val is deprecated.  Use path_planning-msg:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PathResult>) ostream)
  "Serializes a message object of type '<PathResult>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'result))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'result))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PathResult>) istream)
  "Deserializes a message object of type '<PathResult>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'result) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'result)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Point))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PathResult>)))
  "Returns string type for a message object of type '<PathResult>"
  "path_planning/PathResult")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PathResult)))
  "Returns string type for a message object of type 'PathResult"
  "path_planning/PathResult")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PathResult>)))
  "Returns md5sum for a message object of type '<PathResult>"
  "5ac55cb602cab21c0a526eb965fe531a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PathResult)))
  "Returns md5sum for a message object of type 'PathResult"
  "5ac55cb602cab21c0a526eb965fe531a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PathResult>)))
  "Returns full string definition for message of type '<PathResult>"
  (cl:format cl:nil "geometry_msgs/Point[] result~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PathResult)))
  "Returns full string definition for message of type 'PathResult"
  (cl:format cl:nil "geometry_msgs/Point[] result~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PathResult>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'result) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PathResult>))
  "Converts a ROS message object to a list"
  (cl:list 'PathResult
    (cl:cons ':result (result msg))
))
