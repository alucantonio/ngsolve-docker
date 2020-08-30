# TODO: This script has to be completed and tested. Currently not working.

# These commands are for compilation from sources
#ENV CC=clang
#ENV CXX=clang++

#ENV BASEDIR=/root
#RUN mkdir -p $BASEDIR
#RUN cd $BASEDIR && git clone https://github.com/NGSolve/ngsolve.git ngsolve-src
#RUN cd $BASEDIR/ngsolve-src && git submodule update --init --recursive
#RUN mkdir $BASEDIR/ngsolve-build
#RUN mkdir $BASEDIR/ngsolve-install
#RUN cd $BASEDIR/ngsolve-build

#RUN cmake -DCMAKE_INSTALL_PREFIX=${BASEDIR}/ngsolve-install ${BASEDIR}/ngsolve-src
#RUN make -j install
#RUN echo "export NETGENDIR=${BASEDIR}/ngsolve-install/bin" >> ~/.bashrc
#RUN echo "export PATH=\$NETGENDIR:\$PATH" >> ~/.bashrc
#RUN export PYTHONPATH_TMP=`python3 -c "from distutils.sysconfig import get_python_lib; print(get_python_lib(1,0,''))"`
#RUN echo "export PYTHONPATH=\$NETGENDIR/../${PYTHONPATH_TMP}:\$PATH" >> ~/.bashrc
#WORKDIR /root

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
