# Image de base légère de Node.js
FROM node:18.16.0-alpine3.17

# Créé un répertoire de travail pour l'application et s'y déplace
WORKDIR /app

# Copie les fichiers package.json et package-lock.json (s'il existe)
COPY package*.json .

# Installe les dépendance de l'application
RUN npm install --omit=dev

# Installe les dépendances musl-locales et tzdata pour le fuseau horaire
RUN apk --no-cache add musl-locales
RUN apk --no-cache add tzdata

# Copie l'application
COPY . .

# Expose le port sur lequel l'applcation écoute
EXPOSE 8080

#Créer les volumes
VOLUME [ "/etc/timezone:/etc/timezone:ro","/etc/localdate:/etc/localdate:ro" ]

# Démarre l'application
CMD ["npm", "start"]
