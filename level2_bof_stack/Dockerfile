FROM ubuntu:20.04

# Instalar dependencias necesarias para passwd y pam
RUN apt update && DEBIAN_FRONTEND=noninteractive apt install -y \
    gcc socat xinetd openssh-server passwd \
    libpam-modules libpam-modules-bin libpam0g

# Recibir la flag anterior como argumento
ARG PREV_FLAG
ENV PREV_FLAG=${PREV_FLAG}

# Crear usuario level2
RUN useradd -m -s /bin/bash level2

WORKDIR /home/level2

# Copiar fuente y compilar
COPY challenge.c .
RUN gcc -no-pie -fno-stack-protector challenge.c -o challenge

# Copiar flag y configuración
COPY flag.txt flag.txt
COPY sshd_config /etc/ssh/sshd_config
COPY entrypoint.sh /entrypoint.sh

# Configuración de entorno
RUN chmod +x /entrypoint.sh && \
    mkdir -p /var/run/sshd && \
    chown level2:level2 challenge flag.txt && \
    chmod 440 flag.txt && \
    echo "level2:${PREV_FLAG}" | chpasswd

EXPOSE 22
CMD ["/entrypoint.sh"]
