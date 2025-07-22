FROM ubuntu:20.04

# Instala herramientas necesarias
RUN apt update && DEBIAN_FRONTEND=noninteractive apt install -y gcc socat xinetd openssh-server passwd

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

# Preparar permisos, entorno SSH y contraseña desde flag
RUN chmod +x /entrypoint.sh && \
    mkdir -p /var/run/sshd && \
    chown level3:level3 challenge flag.txt && \
    chmod 440 flag.txt && \
    FLAG=$(cat flag.txt) && \
    echo "level3:${FLAG}" | chpasswd

# Exponer puerto SSH (aunque solo se usará en level1)
EXPOSE 22

# Ejecutar entrypoint para iniciar sshd
CMD ["/entrypoint.sh"]
