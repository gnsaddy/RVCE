from django.db import models

# Create your models here.


class Emp(models.Model):
    emp_id = models.CharField(max_length=30)
    name = models.CharField(max_length=40)
    age = models.IntegerField()
    address = models.CharField(max_length=100)

    def __str__(self):
        return self.name
