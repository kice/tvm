/*!
 *  Copyright (c) 2018 by Contributors
 * \file unary.cc
 * \brief Unary operators.
 */
#include <tvm/relay/expr.h>
#include <tvm/relay/op.h>
#include "../type_relations.h"
#include "../op_common.h"

namespace tvm {
namespace relay {


RELAY_REGISTER_UNARY_OP("relay.op._make.", "log")
.describe(R"code(Returns the log input array, computed element-wise.

.. math::
   log(x)

)code" TVM_ADD_FILELINE)
.set_support_level(1)
.add_type_rel("Identity", IdentityRel);

RELAY_REGISTER_UNARY_OP("relay.op._make.", "exp")
.describe(R"code(Returns the exp input array, computed element-wise.

.. math::
   \exp(x)

)code" TVM_ADD_FILELINE)
.set_support_level(1)
.add_type_rel("Identity", IdentityRel);


RELAY_REGISTER_UNARY_OP("relay.op._make.", "sqrt")
.describe(R"code(Returns the sqrt input array, computed element-wise.

.. math::
   sqrt(x)

)code" TVM_ADD_FILELINE)
.set_support_level(1)
.add_type_rel("Identity", IdentityRel);

RELAY_REGISTER_UNARY_OP("relay.op._make.", "zeros_like")
.describe(R"code(Returns an array of zeros, with same type and shape as the input.
)code" TVM_ADD_FILELINE)
.set_support_level(1)
.add_type_rel("Identity", IdentityRel);

RELAY_REGISTER_UNARY_OP("relay.op._make.", "ones_like")
.describe(R"code(Returns an array of ones, with same type and shape as the input.
)code" TVM_ADD_FILELINE)
.set_support_level(1)
.add_type_rel("Identity", IdentityRel);

RELAY_REGISTER_UNARY_OP("relay.op._make.", "sigmoid")
.describe(R"code(Returns the sigmoid input array, computed element-wise.

.. math::
   sigmoid(x)

)code" TVM_ADD_FILELINE)
.set_support_level(1)
.add_type_rel("Identity", IdentityRel);

RELAY_REGISTER_UNARY_OP("relay.op._make.", "copy")
.describe(R"code(Copy a tensor.
)code" TVM_ADD_FILELINE)
.set_support_level(3)
.add_type_rel("Identity", IdentityRel);

// Clip
struct ClipAttrs : public tvm::AttrsNode<ClipAttrs> {
  double a_min;
  double a_max;

  TVM_DECLARE_ATTRS(ClipAttrs, "relay.attrs.ClipAttrs") {
  TVM_ATTR_FIELD(a_min)
    .describe("The minimum clip value.");
  TVM_ATTR_FIELD(a_max)
    .describe("The maximum clip value.");
  }
};

TVM_REGISTER_API("relay.op._make.clip")
  .set_body_typed<Expr(Expr, double, double)>([](Expr a, double a_min, double a_max) {
      auto attrs = make_node<ClipAttrs>();
      attrs->a_min = a_min;
      attrs->a_max = a_max;
      static const Op& op = Op::Get("clip");
    return CallNode::make(op, {a}, Attrs(attrs), {});
  });

RELAY_REGISTER_OP("clip")
  .describe(R"code(Clip tensor values.
  This function takes a tensor, a minimum value `a_min`, and a maximum value `a_max`, and returns a clipped tensor where all values below `a_min` are set to `a_min` and all values above `a_max` are set to `a_max`. `a_min` and `a_max` are cast to the tensor's dtype.
  )code" TVM_ADD_FILELINE)
  .set_num_inputs(1)
  .add_argument("tensor", "Tensor", "The input tensor.")
  .set_support_level(3)
  .add_type_rel("Clip", IdentityRel);


RELAY_REGISTER_UNARY_OP("relay.op._make.", "floor")
.describe(R"code(Returns the floor of input array, computed element-wise.
)code" TVM_ADD_FILELINE)
.set_support_level(3)
.add_type_rel("Identity", IdentityRel);

RELAY_REGISTER_UNARY_OP("relay.op._make.", "ceil")
.describe(R"code(Returns the ceil of input array, computed element-wise.

.. math::
   ceil(x)

)code" TVM_ADD_FILELINE)
.set_support_level(3)
.add_type_rel("Identity", IdentityRel);

RELAY_REGISTER_UNARY_OP("relay.op._make.", "trunc")
.describe(R"code(Returns the trunc of input array, computed element-wise.

.. math::
   trunc(x)

)code" TVM_ADD_FILELINE)
.set_support_level(3)
.add_type_rel("Identity", IdentityRel);

RELAY_REGISTER_UNARY_OP("relay.op._make.", "round")
.describe(R"code(Returns the round of input array, computed element-wise.

.. math::
   round(x)

)code" TVM_ADD_FILELINE)
.set_support_level(3)
.add_type_rel("Identity", IdentityRel);

RELAY_REGISTER_UNARY_OP("relay.op._make.", "abs")
.describe(R"code(Returns the abs of input array, computed element-wise.

.. math::
   abs(x)

)code" TVM_ADD_FILELINE)
.set_support_level(3)
.add_type_rel("Identity", IdentityRel);

RELAY_REGISTER_UNARY_OP("relay.op._make.", "tanh")
.describe(R"code(Returns the tanh of input array, computed element-wise.

.. math::
   Y = sinh(X) / cosh(X)

)code" TVM_ADD_FILELINE)
.set_support_level(1)
.add_type_rel("Identity", IdentityRel);

RELAY_REGISTER_UNARY_OP("relay.op._make.", "negative")
.describe(R"code(Returns the numeric negative of input array, computed element-wise.

.. math::
   -(x)

)code" TVM_ADD_FILELINE)
.set_support_level(3)
.add_type_rel("Identity", IdentityRel);

}  // namespace relay
}  // namespace tvm
