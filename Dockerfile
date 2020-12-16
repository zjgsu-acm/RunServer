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
  apt update && \
  apt -y upgrade && \
  apt -y install gcc-8 g++-8 gdb make dpkg-dev flex adoptopenjdk-8-hotspot && \
  apt -y install python python-virtualenv python3 python3-virtualenv && \
  mkdir -p /usr/local/cjudger/venv/ && \
  virtualenv --no-setuptools --no-pip --no-wheel -p /usr/bin/python2 /usr/local/cjudger/venv/py2 && \
  virtualenv --no-setuptools --no-pip --no-wheel -p /usr/bin/python3 /usr/local/cjudger/venv/py3 && \
  ln -s /usr/local/cjudger/venv/py2/bin/python2 /usr/local/cjudger/py2 && \
  ln -s /usr/local/cjudger/venv/py3/bin/python3 /usr/local/cjudger/py3 && \
  rm -rf /var/lib/apt/lists/*

ENV GO111MODULE=on
ENV GOPROXY=https://goproxy.cn

RUN mkdir -p $GOPATH/src/github.com/ZJGSU-ACM/
ADD . $GOPATH/src/github.com/ZJGSU-ACM/RunServer
Add docker-entrypoint.sh /docker-entrypoint.sh

# Build OJ
RUN \
  cd $GOPATH/src/github.com/ZJGSU-ACM/RunServer && \
  ./make.sh

# Define working directory.
WORKDIR $GOPATH/src

# Expose ports
EXPOSE 8888

ENTRYPOINT ["/docker-entrypoint.sh"]

CMD RunServer
