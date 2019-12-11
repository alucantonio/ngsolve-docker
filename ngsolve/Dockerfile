FROM ngsolve-base
WORKDIR /root/ngsolve-build
#RUN apt install -y gcc
ENV CC=gcc
ENV CXX=g++
RUN apt install -y gfortran
RUN /bin/bash -c "source /opt/intel/bin/compilervars.sh intel64 &&  cmake -DCMAKE_INSTALL_PREFIX=${BASEDIR}/ngsolve-install \
	-DUSE_MPI=ON \
	-DUSE_GUI=OFF \
	-DUSE_MKL=ON \
	-DMAX_SYS_DIM=6 \
	-DMKL_STATIC=ON \
	-DUSE_MUMPS=ON \
	${BASEDIR}/ngsolve-src"
RUN /bin/bash -c "source /opt/intel/bin/compilervars.sh intel64 && make -j8 install"
RUN echo "export PYTHONPATH=\$NETGENDIR/../lib/python3/dist-packages/:${PYTHONPATH}" >> ~/.bashrc
RUN echo "source /opt/intel/bin/compilervars.sh intel64" >> ~/.bashrc

WORKDIR /root


ENTRYPOINT ["sh", "-c", "/usr/sbin/sshd && tail -f /dev/null"]
