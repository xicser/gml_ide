; Auto-generated. Do not edit!


(cl:in-package event_comm-msg)


;//! \htmlinclude EventAbnormal.msg.html

(cl:defclass <EventAbnormal> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass EventAbnormal (<EventAbnormal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <EventAbnormal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'EventAbnormal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name event_comm-msg:<EventAbnormal> is deprecated: use event_comm-msg:EventAbnormal instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EventAbnormal>) ostream)
  "Serializes a message object of type '<EventAbnormal>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <EventAbnormal>) istream)
  "Deserializes a message object of type '<EventAbnormal>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<EventAbnormal>)))
  "Returns string type for a message object of type '<EventAbnormal>"
  "event_comm/EventAbnormal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EventAbnormal)))
  "Returns string type for a message object of type 'EventAbnormal"
  "event_comm/EventAbnormal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EventAbnormal>)))
  "Returns md5sum for a message object of type '<EventAbnormal>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EventAbnormal)))
  "Returns md5sum for a message object of type 'EventAbnormal"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EventAbnormal>)))
  "Returns full string definition for message of type '<EventAbnormal>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EventAbnormal)))
  "Returns full string definition for message of type 'EventAbnormal"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EventAbnormal>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EventAbnormal>))
  "Converts a ROS message object to a list"
  (cl:list 'EventAbnormal
))
