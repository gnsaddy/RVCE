from django.db import models


class Stock(models.Model):
    sid = models.AutoField(primary_key=True)
    sname = models.CharField(max_length=200)
    quant = models.IntegerField()

