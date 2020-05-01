FROM golang:1.14.2
MAINTAINER Happier233 "happier233@qq.com"

# Install base software.
# RUN \
#   apt update && \
#   apt -y install apt-transport-https ca-certificates

RUN \
  echo 'deb https://mirrors.tuna.tsinghua.edu.cn/debian/ buster main contrib non-free' > /etc/apt/sources.list && \
  echo 'deb https://mirrors.tuna.tsinghua.edu.cn/debian/ buster-updates main contrib non-free' >> /etc/apt/sources.list && \
  echo 'deb https://mirrors.tuna.tsinghua.edu.cn/debian/ buster-backports main contrib non-free' >> /etc/apt/sources.list && \
  echo 'deb https://mirrors.tuna.tsinghua.edu.cn/debian-security buster/updates main contrib non-free' >> /etc/apt/sources.list

RUN ["/bin/bash", "-c", "wget -qO - https://adoptopenjdk.jfrog.io/adoptopenjdk/api/gpg/key/public | apt-key add -"]
RUN ["/bin/bash", "-c", "echo 'deb http://mirrors.tuna.tsinghua.edu.cn/AdoptOpenJDK/deb buster main' > /etc/apt/sources.list.d/AdoptOpenJDK.list"]

RUN \
  apt-get update && \
  apt -y upgrade && \
  apt -y install gcc-7 g++-7 gdb make dpkg-dev flex adoptopenjdk-8-hotspot && \
  apt -y install python python-virtualenv python3 python3-virtualenv && \
  mkdir /usr/local/cjudger/ && \
  mkdir /usr/local/cjudger/venv/ && \
  virtualenv --no-setuptools --no-pip --no-wheel -p /usr/bin/python2 /usr/local/cjudger/venv/py2 && \
  virtualenv --no-setuptools --no-pip --no-wheel -p /usr/bin/python3 /usr/local/cjudger/venv/py3 && \
  ln -s /usr/local/cjudger/venv/py2/bin/python2 /usr/local/cjudger/py2 && \
  ln -s /usr/local/cjudger/venv/py3/bin/python3 /usr/local/cjudger/py3 && \
  rm -rf /var/lib/apt/lists/*

ENV GOPROXY=https://mirrors.aliyun.com/goproxy/
ARG COPY_WEB=0
ARG COPY_VJ=0
ARG COPY_REST=0

RUN mkdir -p $GOPATH/src/github.com/ZJGSU-ACM/
ADD ./restweb $GOPATH/src/restweb
ADD ./github.com/ZJGSU-ACM/vjudger $GOPATH/src/github.com/ZJGSU-ACM/vjudger
ADD ./github.com/ZJGSU-ACM/GoOnlineJudge $GOPATH/src/github.com/ZJGSU-ACM/GoOnlineJudge
ADD ./github.com/ZJGSU-ACM/RunServer $GOPATH/src/github.com/ZJGSU-ACM/RunServer

# Build OJ
RUN \
  cd $GOPATH/src/github.com/ZJGSU-ACM/RunServer && \
  ./make.sh

# Define working directory.
WORKDIR $GOPATH/src

# Expose ports
EXPOSE 8888

CMD RunServer