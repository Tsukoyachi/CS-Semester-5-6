# Image de base légère de Node.js
FROM node:18.14.1

# Créé un répertoire de travail pour l'application et s'y déplace
WORKDIR /app

# Copie les fichiers package.json et package-lock.json (s'il existe)
COPY package*.json .

# Installe les dépendance de l'application
RUN npm install --omit=dev

# Installe les dépendances musl-locales et tzdata pour le fuseau horaire
RUN apk add musl-locales
RUN apk add tzdata

# Copie l'application
COPY . .

# Expose le port sur lequel l'applcation écoute
EXPOSE 8080

# Démarre l'application
CMD ["npm", "start"]
