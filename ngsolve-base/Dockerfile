FROM ubuntu:20.04

ENV TZ=Europe/Rome
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# Language/locale settings
ENV LANG it_IT.UTF-8
RUN echo $LANG UTF-8 > /etc/locale.gen && \
    apt-get update && apt-get install -y locales && \
    update-locale --reset LANG=$LANG

RUN apt-get update && apt install -y software-properties-common libpython3.8 sudo
RUN add-apt-repository ppa:ngsolve/ngsolve
RUN apt-get update && apt-get install -y ngsolve python3-pip
RUN pip3 install jupyterlab scipy matplotlib ipywidgets

RUN useradd -m ngsolve && echo "ngsolve:ngsolve" | chpasswd && adduser ngsolve sudo

RUN apt-get install -y firefox pluma nano vim-gui-common wget unzip

USER ngsolve

# jupyter notebook extensions for interactive visualization
RUN jupyter nbextension install --py widgetsnbextension
RUN jupyter nbextension enable --py widgetsnbextension
RUN jupyter nbextension install --user --py ngsolve
RUN jupyter nbextension enable --user --py ngsolve

# The command needed to install the NGSolve Jupyter lab extension depends on the system and is generated with the following code:
# python3 -c 'import ngsolve.webgui; ngsolve.webgui.howtoInstallJupyterLabextension()'

# Install ngsolve i-tutorials
WORKDIR /home/ngsolve
RUN wget https://ngsolve.org/docu/latest/i-tutorials.zip && unzip i-tutorials.zip
RUN rm i-tutorials.zip

ENV USER=ngsolve
ENV SHELL=/bin/bash

COPY run_jupyterlab.sh /home/ngsolve

WORKDIR /home/ngsolve
