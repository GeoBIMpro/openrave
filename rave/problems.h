// -*- coding: utf-8 -*-
// Copyright (C) 2006-2010 Rosen Diankov (rosen.diankov@gmail.com)
//
// This file is part of OpenRAVE.
// OpenRAVE is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
/** \file problems.h
    \brief Problem instances and functions related to characterization of robotics problems.
*/
#ifndef OPENRAVE_COMMAND_PROBLEM_INSTANCE_H
#define OPENRAVE_COMMAND_PROBLEM_INSTANCE_H

namespace OpenRAVE {

/** \brief <b>[interface]</b> A loadable module of user code meant to solve a specific problem in robotics. See \ref arch_problem.
    \ingroup interfaces
*/
class RAVE_API ProblemInstance : public InterfaceBase
{
public:
    ProblemInstance(EnvironmentBasePtr penv) : InterfaceBase(PT_ProblemInstance, penv) {}
    virtual ~ProblemInstance() {}

    /// return the static interface type this class points to (used for safe casting)
    static inline InterfaceType GetInterfaceTypeStatic() { return PT_ProblemInstance; }
    
    /// gets called every time a problem instance is loaded to initialize the problem.
    /// Robots might not necessarily be set before this function call
    /// returns 0 on success
    virtual int main(const std::string& cmd) { return 0; }

    /// called when problem gets unloaded from environment
    virtual void Destroy() {}

    /// called when environment is reset
    virtual void Reset() {}

    virtual bool SimulationStep(dReal fElapsedTime) {return false;}
private:
    virtual const char* GetHash() const { return OPENRAVE_PROBLEM_HASH; }
};

} // end namespace OpenRAVE

#endif
