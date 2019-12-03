from django.db import models

# Create your models here.


class Emp(models.Model):
    empid = models.CharField(max_length=30)
    name = models.CharField(max_length=50)
    address = models.CharField(max_length=100)
    contact = models.CharField(max_length=20)

    def __str__(self):
        return self.name
