
(cl:in-package :asdf)

(defsystem "act_osflock_test-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "IDQP" :depends-on ("_package_IDQP"))
    (:file "_package_IDQP" :depends-on ("_package"))
  ))