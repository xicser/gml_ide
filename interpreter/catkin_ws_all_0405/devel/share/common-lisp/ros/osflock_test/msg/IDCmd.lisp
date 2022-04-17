; Auto-generated. Do not edit!


(cl:in-package osflock_test-msg)


;//! \htmlinclude IDCmd.msg.html

(cl:defclass <IDCmd> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type cl:fixnum
    :initform 0)
   (cmd
    :reader cmd
    :initarg :cmd
    :type cl:string
    :initform ""))
)

(cl:defclass IDCmd (<IDCmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <IDCmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'IDCmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name osflock_test-msg:<IDCmd> is deprecated: use osflock_test-msg:IDCmd instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <IDCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader osflock_test-msg:id-val is deprecated.  Use osflock_test-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'cmd-val :lambda-list '(m))
(cl:defmethod cmd-val ((m <IDCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader osflock_test-msg:cmd-val is deprecated.  Use osflock_test-msg:cmd instead.")
  (cmd m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <IDCmd>) ostream)
  "Serializes a message object of type '<IDCmd>"
  (cl:let* ((signed (cl:slot-value msg 'id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'cmd))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'cmd))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <IDCmd>) istream)
  "Deserializes a message object of type '<IDCmd>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'cmd) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'cmd) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<IDCmd>)))
  "Returns string type for a message object of type '<IDCmd>"
  "osflock_test/IDCmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'IDCmd)))
  "Returns string type for a message object of type 'IDCmd"
  "osflock_test/IDCmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<IDCmd>)))
  "Returns md5sum for a message object of type '<IDCmd>"
  "8de13cc4a5bfcc15ab1cf03b69806e36")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'IDCmd)))
  "Returns md5sum for a message object of type 'IDCmd"
  "8de13cc4a5bfcc15ab1cf03b69806e36")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<IDCmd>)))
  "Returns full string definition for message of type '<IDCmd>"
  (cl:format cl:nil "int8 id # agent id~%string cmd # agent command, include takeoff start land~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'IDCmd)))
  "Returns full string definition for message of type 'IDCmd"
  (cl:format cl:nil "int8 id # agent id~%string cmd # agent command, include takeoff start land~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <IDCmd>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'cmd))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <IDCmd>))
  "Converts a ROS message object to a list"
  (cl:list 'IDCmd
    (cl:cons ':id (id msg))
    (cl:cons ':cmd (cmd msg))
))
