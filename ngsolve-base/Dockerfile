FROM ubuntu:20.04
ENV TZ=Europe/Vienna
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get update && apt install -y git vim cmake python3 python3-tk python3-pip libpython3-dev libxmu-dev tk-dev tcl-dev cmake git clang libglu1-mesa-dev liblapacke-dev
ENV CC=clang
ENV CXX=clang++
RUN apt install -y openssh-server xauth
RUN mkdir /var/run/sshd \
    && mkdir /root/.ssh \
    && chmod 700 /root/.ssh \
    && ssh-keygen -A \
    && sed -i "s/^.*PasswordAuthentication.*$/PasswordAuthentication no/" /etc/ssh/sshd_config \
    && sed -i "s/^.*X11Forwarding.*$/X11Forwarding yes/" /etc/ssh/sshd_config \
    && sed -i "s/^.*X11UseLocalhost.*$/X11UseLocalhost no/" /etc/ssh/sshd_config \
    && grep "^X11UseLocalhost" /etc/ssh/sshd_config || echo "X11UseLocalhost no" >> /etc/ssh/sshd_config
RUN echo "ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQCgva7zUoKWCbIFF+hd2FCRbj9blmCRMwEt9tI0x13FG3abatmymSa4nbwdPrw8ljSkGI7Xc62PCmJXbc73+vnmuh97A4azJ4fox4nfzRx/O7Hjnmnf210P9r7IqE4Dxj7KgFt90kjNaVKHazDPB01CNB0WkCpiqzUSHQ8KnuH2bcgQh6H+ILJjZGDS4pVkOGWZAmc7jT4e0KiXkYU8oh06NCykDdKtnHEe/UbG2Bj4B370ch7++1wntDWu+S7TjM497sZ/LCI4jFcpt7mC8FXIu8nFvihd90da4tXnnfdixeBqdsLrnBeocbXxBHx/j3Num1RVpEn8L35qMUBRe1Ef max@iMax.local" > /root/.ssh/authorized_keys

RUN wget https://apt.repos.intel.com/intel-gpg-keys/GPG-PUB-KEY-INTEL-SW-PRODUCTS-2019.PUB && apt-key add GPG-PUB-KEY-INTEL-SW-PRODUCTS-2019.PUB && rm GPG-PUB-KEY-INTEL-SW-PRODUCTS-2019.PUB

RUN wget https://apt.repos.intel.com/setup/intelproducts.list -O /etc/apt/sources.list.d/intelproducts.list
RUN echo deb https://apt.repos.intel.com/mkl all main > /etc/apt/sources.list.d/intel-mkl.list
RUN echo deb https://apt.repos.intel.com/mpi all main > /etc/apt/sources.list.d/intel-mpi.list
RUN apt-get update 
RUN apt-get install intel-mkl-2019.4-070 -y
RUN apt-get install intel-mpi-2019.4-070 -y

ENV BASEDIR=/root
RUN mkdir -p $BASEDIR
RUN cd $BASEDIR && git clone https://github.com/NGSolve/ngsolve.git ngsolve-src
RUN cd $BASEDIR/ngsolve-src && git submodule update --init --recursive
RUN mkdir $BASEDIR/ngsolve-build
RUN mkdir $BASEDIR/ngsolve-install
RUN cd $BASEDIR/ngsolve-build

#RUN cmake -DCMAKE_INSTALL_PREFIX=${BASEDIR}/ngsolve-install ${BASEDIR}/ngsolve-src
#RUN make -j install
RUN echo "export NETGENDIR=${BASEDIR}/ngsolve-install/bin" >> ~/.bashrc
RUN echo "export PATH=\$NETGENDIR:\$PATH" >> ~/.bashrc
RUN export PYTHONPATH_TMP=`python3 -c "from distutils.sysconfig import get_python_lib; print(get_python_lib(1,0,''))"`
RUN echo "export PYTHONPATH=\$NETGENDIR/../${PYTHONPATH_TMP}:\$PATH" >> ~/.bashrc
WORKDIR /root
