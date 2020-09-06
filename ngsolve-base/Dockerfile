FROM ubuntu:20.04

ENV TZ=Europe/Rome
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN env DEBIAN_FRONTEND=noninteractive

# Language/locale settings
ENV LANG it_IT.UTF-8
RUN echo $LANG UTF-8 > /etc/locale.gen && \
    apt-get update && apt-get install -y locales && \
    update-locale --reset LANG=$LANG

RUN apt-get update && apt-get install -y dbus-x11 procps psmisc && \
    apt-get install -y xdg-utils xdg-user-dirs menu-xdg mime-support \
          desktop-file-utils && \
    apt-get install -y mesa-utils mesa-utils-extra libxv1

# Mate desktop (minimal)
#RUN apt-get update && env DEBIAN_FRONTEND=noninteractive apt-get install -y ubuntu-mate-desktop
RUN env DEBIAN_FRONTEND=noninteractive apt-get install -y caja folder-color-caja gnome-colors-common gnome-icon-theme \
gnome-orca indicator-messages indicator-power indicator-session indicator-sound mate-accessibility-profiles \
mate-applet-appmenu mate-applet-brisk-menu mate-desktop mate-dock-applet mate-hud mate-icon-theme mate-menu \
mate-menus mate-system-monitor mate-tweak mate-user-guide mate-utils mate-window-applets-common \
mate-window-buttons-applet mate-window-menu-applet mate-window-title-applet plank \
plymouth-theme-ubuntu-mate-logo plymouth-theme-ubuntu-mate-text ubuntu-mate-artwork ubuntu-mate-core \
ubuntu-mate-default-settings ubuntu-mate-guide ubuntu-mate-icon-themes ubuntu-mate-themes \
ubuntu-mate-wallpapers* ubuntu-standard --no-install-recommends

RUN apt-get install -y software-properties-common libpython3.8 sudo
RUN add-apt-repository ppa:ngsolve/ngsolve
RUN apt-get update && apt-get install -y ngsolve python3-pip
RUN pip3 install jupyterlab scipy matplotlib ipywidgets mako

RUN useradd -m ngsolve && echo "ngsolve:ngsolve" | chpasswd && adduser ngsolve sudo

RUN apt-get install -y firefox pluma nano vim-gui-common wget unzip

# TODO: find another web browser
RUN env DEBIAN_FRONTEND=noninteractive apt-get install -y chromium-browser
RUN snap install chromium

USER ngsolve

# jupyter notebook extensions for interactive visualization
RUN jupyter nbextension install --py widgetsnbextension
RUN jupyter nbextension enable --py widgetsnbextension
RUN jupyter nbextension install --user --py ngsolve
RUN jupyter nbextension enable --user --py ngsolve

# The command needed to install the NGSolve Jupyter lab extension depends on the system and is generated with the following code:
# python3 -c 'import ngsolve.webgui; ngsolve.webgui.howtoInstallJupyterLabextension()'

COPY run_jupyterlab.sh /home/ngsolve

# Install ngsolve i-tutorials
WORKDIR /home/ngsolve
RUN wget https://ngsolve.org/docu/latest/i-tutorials.zip && unzip i-tutorials.zip
RUN rm i-tutorials.zip

ENV USER=ngsolve
ENV SHELL=/bin/bash

CMD ["mate-session"]
