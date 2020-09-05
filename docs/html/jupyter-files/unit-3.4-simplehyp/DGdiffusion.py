from ngsolve import *

def AddArtificialDiffusion(a,Ubnd,magnitude,compile=True,true_compile=False,compile_wait=True):
    if true_compile and not compile:
        raise Excpetion("you need compile=True to active true_compile")
    
    if len(a.integrators) > 2:
        print("it seems you already added artificial diffusion - I will not add more")
        return None
        
    fes = a.space
    U,V = fes.TnT()
    Uhat = U.Other(bnd=Ubnd)
    mesh = fes.mesh
    h = specialcf.mesh_size
    n = specialcf.normal(fes.mesh.dim)
    order = fes.globalorder
    diff = magnitude * 0.5 * h / order
    gamma = 10

    def avg(Q,Q2):
        return 0.5*Q+0.5*Q2
    
    ints = []
    if compile:
        form1 = (diff * InnerProduct(grad(U),grad(V))).Compile(true_compile,wait=compile_wait)
    else:
        form1 = diff * InnerProduct(grad(U),grad(V))
    ints.append(SymbolicBFI ( form1 ))
    if compile:
        form2 = (diff * (- InnerProduct(avg(grad(U).trans,grad(U.Other()).trans)*n,V-V.Other())
                                     - InnerProduct(avg(grad(V).trans,grad(V.Other()).trans)*n,U-Uhat) 
                                     + gamma*order**2/h*InnerProduct(U-Uhat,V-V.Other()))).Compile(true_compile,wait=compile_wait)
    else:
        form2 = (diff * (- InnerProduct(avg(grad(U).trans,grad(U.Other()).trans)*n,V-V.Other())
                                     - InnerProduct(avg(grad(V).trans,grad(V.Other()).trans)*n,U-Uhat) 
                                     + gamma*order**2/h*InnerProduct(U-Uhat,V-V.Other())))
    ints.append(SymbolicBFI (form2, VOL, skeleton=True))
    # ints.append(SymbolicBFI (diff * (- InnerProduct(grad(U).trans*n,V)
    #                                  - InnerProduct(grad(V).trans*n,U-Uhat) 
    #                                  + gamma*order**2/h*InnerProduct(U-Uhat,V)), BND, skeleton=True))
    for integrator in ints:
        a += integrator
