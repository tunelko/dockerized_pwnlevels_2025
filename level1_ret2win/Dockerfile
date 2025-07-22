
FROM ubuntu:20.04

RUN apt update && DEBIAN_FRONTEND=noninteractive apt install -y gcc socat xinetd openssh-server

RUN useradd -m level1
WORKDIR /home/level1

COPY challenge.c .
RUN gcc -no-pie -fno-stack-protector challenge.c -o challenge
    
COPY flag.txt flag.txt
COPY sshd_config /etc/ssh/sshd_config
COPY entrypoint.sh /entrypoint.sh

RUN chmod +x /entrypoint.sh && \
    mkdir -p /var/run/sshd && \
    chown level1:level1 challenge flag.txt && \
    chmod 440 flag.txt

EXPOSE 22
CMD ["/entrypoint.sh"]
