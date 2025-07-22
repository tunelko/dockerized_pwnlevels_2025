FROM ubuntu:20.04

RUN apt update && DEBIAN_FRONTEND=noninteractive apt install -y gcc socat xinetd openssh-server passwd

# Crear usuario level2
RUN useradd -m -s /bin/bash level2

WORKDIR /home/level2

# Copiar fuente y compilar binario
COPY challenge.c .
RUN gcc -no-pie -fno-stack-protector challenge.c -o challenge

# Copiar flag y configuración
COPY flag.txt flag.txt
COPY flag_level1.txt flag_level1.txt

COPY sshd_config /etc/ssh/sshd_config
COPY entrypoint.sh /entrypoint.sh

# Preparar permisos y entorno
RUN chmod +x /entrypoint.sh && \
    mkdir -p /var/run/sshd && \
    chown level2:level2 challenge flag.txt && \
    chmod 440 flag.txt && \
    # Leer flag y establecerla como contraseña SSH de level2
    FLAG=$(cat flag_level1.txt) && \
    echo "level2:${FLAG}" | chpasswd

EXPOSE 22
CMD ["/entrypoint.sh"]
