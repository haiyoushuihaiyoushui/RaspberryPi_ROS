
(cl:in-package :asdf)

(defsystem "ros_robot-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Active" :depends-on ("_package_Active"))
    (:file "_package_Active" :depends-on ("_package"))
  ))