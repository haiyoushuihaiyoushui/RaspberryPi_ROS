; Auto-generated. Do not edit!


(cl:in-package ros_robot-msg)


;//! \htmlinclude Active.msg.html

(cl:defclass <Active> (roslisp-msg-protocol:ros-message)
  ((direction
    :reader direction
    :initarg :direction
    :type cl:fixnum
    :initform 0)
   (speed
    :reader speed
    :initarg :speed
    :type cl:fixnum
    :initform 0)
   (ptz
    :reader ptz
    :initarg :ptz
    :type cl:fixnum
    :initform 0))
)

(cl:defclass Active (<Active>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Active>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Active)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ros_robot-msg:<Active> is deprecated: use ros_robot-msg:Active instead.")))

(cl:ensure-generic-function 'direction-val :lambda-list '(m))
(cl:defmethod direction-val ((m <Active>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_robot-msg:direction-val is deprecated.  Use ros_robot-msg:direction instead.")
  (direction m))

(cl:ensure-generic-function 'speed-val :lambda-list '(m))
(cl:defmethod speed-val ((m <Active>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_robot-msg:speed-val is deprecated.  Use ros_robot-msg:speed instead.")
  (speed m))

(cl:ensure-generic-function 'ptz-val :lambda-list '(m))
(cl:defmethod ptz-val ((m <Active>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_robot-msg:ptz-val is deprecated.  Use ros_robot-msg:ptz instead.")
  (ptz m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Active>) ostream)
  "Serializes a message object of type '<Active>"
  (cl:let* ((signed (cl:slot-value msg 'direction)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'speed)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'ptz)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Active>) istream)
  "Deserializes a message object of type '<Active>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'direction) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'speed) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ptz) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Active>)))
  "Returns string type for a message object of type '<Active>"
  "ros_robot/Active")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Active)))
  "Returns string type for a message object of type 'Active"
  "ros_robot/Active")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Active>)))
  "Returns md5sum for a message object of type '<Active>"
  "f804e429aeb8f3511a613f05f7284a12")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Active)))
  "Returns md5sum for a message object of type 'Active"
  "f804e429aeb8f3511a613f05f7284a12")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Active>)))
  "Returns full string definition for message of type '<Active>"
  (cl:format cl:nil "int8 direction~%int8 speed~%int8 ptz~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Active)))
  "Returns full string definition for message of type 'Active"
  (cl:format cl:nil "int8 direction~%int8 speed~%int8 ptz~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Active>))
  (cl:+ 0
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Active>))
  "Converts a ROS message object to a list"
  (cl:list 'Active
    (cl:cons ':direction (direction msg))
    (cl:cons ':speed (speed msg))
    (cl:cons ':ptz (ptz msg))
))
