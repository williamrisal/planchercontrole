import geojson
import random

lat = random.uniform(43.0, 44.0)  # Latitude (coordonnées approximatives de la PACA)
lon = random.uniform(4.0, 7.0)    # Longitude (coordonnées approximatives de la PACA)

side_length = random.uniform(0.6, 0.8)  # Ajustez cette plage selon votre préférence

side_length *= 1.2

coordinates = [
    (lon, lat),
    (lon + side_length, lat),
    (lon + side_length, lat + side_length),
    (lon, lat + side_length),
    (lon, lat)  
]

polygon = geojson.Polygon([coordinates])

feature = geojson.Feature(geometry=polygon, properties={})

feature_collection = geojson.FeatureCollection([feature])

with open('polygone_paca.geojson', 'w') as f:
    geojson.dump(feature_collection, f)

print("Fichier GeoJSON créé : polygone_paca.geojson")
