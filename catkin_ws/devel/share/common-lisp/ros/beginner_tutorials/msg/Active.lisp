; Auto-generated. Do not edit!


(cl:in-package beginner_tutorials-msg)


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
    :type cl:float
    :initform 0.0))
)

(cl:defclass Active (<Active>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Active>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Active)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name beginner_tutorials-msg:<Active> is deprecated: use beginner_tutorials-msg:Active instead.")))

(cl:ensure-generic-function 'direction-val :lambda-list '(m))
(cl:defmethod direction-val ((m <Active>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beginner_tutorials-msg:direction-val is deprecated.  Use beginner_tutorials-msg:direction instead.")
  (direction m))

(cl:ensure-generic-function 'speed-val :lambda-list '(m))
(cl:defmethod speed-val ((m <Active>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beginner_tutorials-msg:speed-val is deprecated.  Use beginner_tutorials-msg:speed instead.")
  (speed m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Active>) ostream)
  "Serializes a message object of type '<Active>"
  (cl:let* ((signed (cl:slot-value msg 'direction)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Active>) istream)
  "Deserializes a message object of type '<Active>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'direction) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'speed) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Active>)))
  "Returns string type for a message object of type '<Active>"
  "beginner_tutorials/Active")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Active)))
  "Returns string type for a message object of type 'Active"
  "beginner_tutorials/Active")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Active>)))
  "Returns md5sum for a message object of type '<Active>"
  "303d95c789e3846c8cef0567c921b988")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Active)))
  "Returns md5sum for a message object of type 'Active"
  "303d95c789e3846c8cef0567c921b988")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Active>)))
  "Returns full string definition for message of type '<Active>"
  (cl:format cl:nil "int8 direction~%float32 speed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Active)))
  "Returns full string definition for message of type 'Active"
  (cl:format cl:nil "int8 direction~%float32 speed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Active>))
  (cl:+ 0
     1
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Active>))
  "Converts a ROS message object to a list"
  (cl:list 'Active
    (cl:cons ':direction (direction msg))
    (cl:cons ':speed (speed msg))
))
