# Image de base légère de Node.js
FROM node:18.16.0-alpine3.17

# Créé un répertoire de travail pour l'application et s'y déplace
WORKDIR /app

# Copie les fichiers package.json et package-lock.json (s'il existe)
COPY --chown=node:node package*.json .

# Installe les dépendance de l'application
RUN npm install --omit=dev

# Installe les dépendances musl-locales et tzdata pour le fuseau horaire
RUN apk --no-cache add musl-locales tzdata

# Créé un user par défaut
USER node

# Copie l'application
COPY --chown=node:node . .

# Démarre l'application
CMD ["npm", "start"]
