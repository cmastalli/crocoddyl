///////////////////////////////////////////////////////////////////////////////
// BSD 3-Clause License
//
// Copyright (C) 2018-2019, LAAS-CNRS
// Copyright note valid unless otherwise stated in individual files.
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#ifndef BINDINGS_PYTHON_CROCODDYL_MULTIBODY_COSTS_FRAME_VELOCITY_HPP_
#define BINDINGS_PYTHON_CROCODDYL_MULTIBODY_COSTS_FRAME_VELOCITY_HPP_

#include "crocoddyl/multibody/costs/frame-velocity.hpp"

namespace crocoddyl {
namespace python {

namespace bp = boost::python;

void exposeCostFrameVelocity() {
  bp::class_<CostModelFrameVelocity, bp::bases<CostModelAbstract> >(
      "CostModelFrameVelocity",
      bp::init<StateMultibody&, ActivationModelAbstract&, FrameMotion, int>(
          bp::args(" self", " state", " activation", " vref", " nu"),
          "Initialize the frame velocity cost model.\n\n"
          ":param state: state of the multibody system\n"
          ":param activation: activation model\n"
          ":param vref: reference frame velocity\n"
          ":param nu: dimension of control vector")[bp::with_custodian_and_ward<1, 2,
                                                                                bp::with_custodian_and_ward<1, 3> >()])
      .def(bp::init<StateMultibody&, ActivationModelAbstract&, FrameMotion>(
          bp::args(" self", " state", " activation", " vref"),
          "Initialize the frame velocity cost model.\n\n"
          "For this case the default nu is equals to model.nv.\n"
          ":param state: state of the multibody system\n"
          ":param activation: activation model\n"
          ":param vref: reference frame velocity")[bp::with_custodian_and_ward<1, 2,
                                                                               bp::with_custodian_and_ward<1, 3> >()])
      .def(bp::init<StateMultibody&, FrameMotion, int>(
          bp::args(" self", " state", " vref", " nu"),
          "Initialize the frame velocity cost model.\n\n"
          "For this case the default activation model is quadratic, i.e.\n"
          "crocoddyl.ActivationModelQuad(6).\n"
          ":param state: state of the multibody system\n"
          ":param vref: reference frame velocity\n"
          ":param nu: dimension of control vector")[bp::with_custodian_and_ward<1, 2>()])
      .def(bp::init<StateMultibody&, FrameMotion>(
          bp::args(" self", " state", " vref"),
          "Initialize the frame velocity cost model.\n\n"
          "For this case the default activation model is quadratic, i.e.\n"
          "crocoddyl.ActivationModelQuad(6), and nu is equals to model.nv.\n"
          ":param state: state of the multibody system\n"
          ":param vref: reference frame velocity")[bp::with_custodian_and_ward<1, 2>()])
      .def("calc", &CostModelFrameVelocity::calc_wrap,
           CostModel_calc_wraps(bp::args(" self", " data", " x", " u=None"),
                                "Compute the frame velocity cost.\n\n"
                                ":param data: cost data\n"
                                ":param x: time-discrete state vector\n"
                                ":param u: time-discrete control input"))
      .def<void (CostModelFrameVelocity::*)(const boost::shared_ptr<CostDataAbstract>&, const Eigen::VectorXd&,
                                            const Eigen::VectorXd&, const bool&)>(
          "calcDiff", &CostModelFrameVelocity::calcDiff_wrap,
          bp::args(" self", " data", " x", " u=None", " recalc=True"),
          "Compute the derivatives of the frame velocity cost.\n\n"
          ":param data: action data\n"
          ":param x: time-discrete state vector\n"
          ":param u: time-discrete control input\n"
          ":param recalc: If true, it updates the state evolution and the cost value.")
      .def<void (CostModelFrameVelocity::*)(const boost::shared_ptr<CostDataAbstract>&, const Eigen::VectorXd&,
                                            const Eigen::VectorXd&)>(
          "calcDiff", &CostModelFrameVelocity::calcDiff_wrap, bp::args(" self", " data", " x", " u"))
      .def<void (CostModelFrameVelocity::*)(const boost::shared_ptr<CostDataAbstract>&, const Eigen::VectorXd&)>(
          "calcDiff", &CostModelFrameVelocity::calcDiff_wrap, bp::args(" self", " data", " x"))
      .def<void (CostModelFrameVelocity::*)(const boost::shared_ptr<CostDataAbstract>&, const Eigen::VectorXd&,
                                            const bool&)>("calcDiff", &CostModelFrameVelocity::calcDiff_wrap,
                                                          bp::args(" self", " data", " x", " recalc"))
      .def("createData", &CostModelFrameVelocity::createData, bp::with_custodian_and_ward_postcall<0, 2>(),
           bp::args(" self", " data"),
           "Create the frame velocity cost data.\n\n"
           "Each cost model has its own data that needs to be allocated. This function\n"
           "returns the allocated data for a predefined cost.\n"
           ":param data: Pinocchio data\n"
           ":return cost data.")
      .add_property("vref", bp::make_function(&CostModelFrameVelocity::get_vref, bp::return_internal_reference<>()),
                    "reference frame velocity");
}

}  // namespace python
}  // namespace crocoddyl

#endif  // BINDINGS_PYTHON_CROCODDYL_MULTIBODY_COSTS_FRAME_VELOCITY_HPP_
