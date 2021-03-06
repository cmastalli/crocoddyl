///////////////////////////////////////////////////////////////////////////////
// BSD 3-Clause License
//
// Copyright (C) 2020-2021, LAAS-CNRS, University of Edinburgh, INRIA
// Copyright note valid unless otherwise stated in individual files.
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#include "crocoddyl/multibody/costs/control-gravity.hpp"
#include "python/crocoddyl/multibody/multibody.hpp"
#include "python/crocoddyl/utils/deprecate.hpp"

namespace crocoddyl {
namespace python {

void exposeCostControlGrav() {  // TODO: Remove once the deprecated update call has been removed in a future
                                // release
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

  bp::register_ptr_to_python<boost::shared_ptr<CostModelControlGrav> >();

  bp::class_<CostModelControlGrav, bp::bases<CostModelResidual> >(
      "CostModelControlGrav",
      "This cost function defines a residual vector as r = a(u) - g(q), "
      "where q, g(q) are the generalized position and gravity vector, "
      "respectively,"
      "and a(u) is the actuated torque.",
      bp::init<boost::shared_ptr<StateMultibody>, boost::shared_ptr<ActivationModelAbstract>, std::size_t>(
          bp::args("self", "state", "activation", "nu"),
          "Initialize the control-gravity cost model.\n\n"
          ":param state: state description\n"
          ":param activation: activation model\n"
          ":param nu: dimension of the control vector"))
      .def(bp::init<boost::shared_ptr<StateMultibody>, boost::shared_ptr<ActivationModelAbstract> >(
          bp::args("self", "state", "activation"),
          "Initialize the control-gravity cost model.\n\n"
          "The default nu is obtained from state.nv.\n"
          ":param state: state description\n"
          ":param activation: activation model"))
      .def(bp::init<boost::shared_ptr<StateMultibody>, std::size_t>(
          bp::args("self", "state", "nu"),
          "Initialize the control-gravity cost model.\n\n"
          "We use ActivationModelQuad as a default activation model (i.e.\n"
          "a=0.5*||r||^2).\n"
          ":param state: state description\n"
          ":param nu: dimension of the control vector"))
      .def(bp::init<boost::shared_ptr<StateMultibody> >(
          bp::args("self", "state"),
          "Initialize the control cost model.\n\n"
          "The default nu is obtained from state.nv. We use ActivationModelQuad \n"
          "as a default activation model (i.e. a=0.5*||r||^2).\n"
          ":param state: state description"));

#pragma GCC diagnostic pop
}

}  // namespace python
}  // namespace crocoddyl
