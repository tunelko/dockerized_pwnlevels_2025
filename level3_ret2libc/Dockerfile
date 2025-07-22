FROM ubuntu:20.04

# Instala herramientas necesarias y soporte para PAM
RUN apt update && DEBIAN_FRONTEND=noninteractive apt install -y \
    gcc socat xinetd openssh-server passwd \
    libpam-modules libpam-modules-bin libpam0g

# Recibir la flag anterior como argumento
ARG PREV_FLAG
ENV PREV_FLAG=${PREV_FLAG}

# Crear usuario level3 con bash como shell
RUN useradd -m -s /bin/bash level3

# Establecer directorio de trabajo
WORKDIR /home/level3

# Copiar código fuente del challenge y compilar
COPY challenge.c .
RUN gcc -no-pie -fno-stack-protector challenge.c -o challenge

# Copiar flag y configuración
COPY flag.txt flag.txt
COPY sshd_config /etc/ssh/sshd_config
COPY entrypoint.sh /entrypoint.sh

# Preparar permisos y contraseña
RUN chmod +x /entrypoint.sh && \
    mkdir -p /var/run/sshd && \
    chown level3:level3 challenge flag.txt && \
    chmod 440 flag.txt && \
    echo "level3:${PREV_FLAG}" | chpasswd

EXPOSE 22
CMD ["/entrypoint.sh"]
