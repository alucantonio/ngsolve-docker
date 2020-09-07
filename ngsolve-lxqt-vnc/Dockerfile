FROM dorowu/ubuntu-desktop-lxde-vnc:focal-lxqt

ENV TZ=Europe/Rome
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN env DEBIAN_FRONTEND=noninteractive

RUN apt-get install -y software-properties-common libpython3.8 sudo
RUN add-apt-repository ppa:ngsolve/ngsolve
RUN apt-get update && apt-get install -y ngsolve python3-pip
RUN pip3 install jupyterlab scipy matplotlib ipywidgets mako

RUN useradd -m ngsolve && echo "ngsolve:ngsolve" | chpasswd && adduser ngsolve sudo

RUN apt-get install -y pluma nano vim-gui-common wget unzip

USER ngsolve

WORKDIR /home/ngsolve
ENV HOME=/home/ngsolve

# jupyter notebook extensions for interactive visualization
RUN jupyter nbextension install --py widgetsnbextension
RUN jupyter nbextension enable --py widgetsnbextension
RUN jupyter nbextension install --user --py ngsolve
RUN jupyter nbextension enable --user --py ngsolve

# The command needed to install the NGSolve Jupyter lab extension depends on the system and is generated with the following code:
# python3 -c 'import ngsolve.webgui; ngsolve.webgui.howtoInstallJupyterLabextension()'

COPY run_jupyterlab.sh /home/ngsolve
COPY run_jupyternb.sh /home/ngsolve

# Install ngsolve i-tutorials
RUN wget https://ngsolve.org/docu/latest/i-tutorials.zip && unzip i-tutorials.zip
RUN rm i-tutorials.zip

#WORKDIR /root
ENV HOME=/home/ubuntu
USER root
