; Auto-generated. Do not edit!


(cl:in-package vsform_test-msg)


;//! \htmlinclude Goal.msg.html

(cl:defclass <Goal> (roslisp-msg-protocol:ros-message)
  ((frame_pos
    :reader frame_pos
    :initarg :frame_pos
    :type geometry_msgs-msg:Point32
    :initform (cl:make-instance 'geometry_msgs-msg:Point32))
   (frame_vel
    :reader frame_vel
    :initarg :frame_vel
    :type geometry_msgs-msg:Point32
    :initform (cl:make-instance 'geometry_msgs-msg:Point32))
   (path_width
    :reader path_width
    :initarg :path_width
    :type cl:float
    :initform 0.0))
)

(cl:defclass Goal (<Goal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Goal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Goal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name vsform_test-msg:<Goal> is deprecated: use vsform_test-msg:Goal instead.")))

(cl:ensure-generic-function 'frame_pos-val :lambda-list '(m))
(cl:defmethod frame_pos-val ((m <Goal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader vsform_test-msg:frame_pos-val is deprecated.  Use vsform_test-msg:frame_pos instead.")
  (frame_pos m))

(cl:ensure-generic-function 'frame_vel-val :lambda-list '(m))
(cl:defmethod frame_vel-val ((m <Goal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader vsform_test-msg:frame_vel-val is deprecated.  Use vsform_test-msg:frame_vel instead.")
  (frame_vel m))

(cl:ensure-generic-function 'path_width-val :lambda-list '(m))
(cl:defmethod path_width-val ((m <Goal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader vsform_test-msg:path_width-val is deprecated.  Use vsform_test-msg:path_width instead.")
  (path_width m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Goal>) ostream)
  "Serializes a message object of type '<Goal>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'frame_pos) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'frame_vel) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'path_width))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Goal>) istream)
  "Deserializes a message object of type '<Goal>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'frame_pos) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'frame_vel) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'path_width) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Goal>)))
  "Returns string type for a message object of type '<Goal>"
  "vsform_test/Goal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Goal)))
  "Returns string type for a message object of type 'Goal"
  "vsform_test/Goal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Goal>)))
  "Returns md5sum for a message object of type '<Goal>"
  "b0c8263c41fcbdd38a6148d2ecdf8e38")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Goal)))
  "Returns md5sum for a message object of type 'Goal"
  "b0c8263c41fcbdd38a6148d2ecdf8e38")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Goal>)))
  "Returns full string definition for message of type '<Goal>"
  (cl:format cl:nil "geometry_msgs/Point32 frame_pos # frame position~%geometry_msgs/Point32 frame_vel # frame velocity~%float32 path_width # path width~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Goal)))
  "Returns full string definition for message of type 'Goal"
  (cl:format cl:nil "geometry_msgs/Point32 frame_pos # frame position~%geometry_msgs/Point32 frame_vel # frame velocity~%float32 path_width # path width~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Goal>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'frame_pos))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'frame_vel))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Goal>))
  "Converts a ROS message object to a list"
  (cl:list 'Goal
    (cl:cons ':frame_pos (frame_pos msg))
    (cl:cons ':frame_vel (frame_vel msg))
    (cl:cons ':path_width (path_width msg))
))
