
(cl:in-package :asdf)

(defsystem "osflock_test-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "IDCmd" :depends-on ("_package_IDCmd"))
    (:file "_package_IDCmd" :depends-on ("_package"))
    (:file "IDQP" :depends-on ("_package_IDQP"))
    (:file "_package_IDQP" :depends-on ("_package"))
  ))