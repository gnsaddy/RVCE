from django.db import models

class Emp(models.Model):
    eid = models.CharField(max_length=30)
    name = models.CharField(max_length=30)
    age = models.IntegerField()
    address = models.TextField()


