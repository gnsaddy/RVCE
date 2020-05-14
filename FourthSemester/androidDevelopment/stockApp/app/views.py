from django.http import HttpResponseRedirect
from django.shortcuts import render, redirect
from django.views.generic import TemplateView

from app.models import Stock


def home(req):
    shelf = Stock.objects.all()
    return render(req, 'index.html', {'shelf': shelf})


def show(req):
    shelf = Stock.objects.all()
    return render(req, 'display.html', {'shelf': shelf})


class Insert(TemplateView):
    def get(self, request, *args, **kwargs):
        product = request.GET['product']
        quantity = request.GET['quantity']
        e = Stock(sname=product, quant=quantity)
        e.save()
        return redirect('index')


class Update(TemplateView):

    def get(self, request, *args, **kwargs):
        stock_id = request.GET['stockid']
        quantity = request.GET['st']

        if request.GET.get('add'):
            obj = Stock.objects.get(sid=stock_id)
            obj.quant = obj.quant + int(quantity)
            obj.save()

        if request.GET.get('remove'):
            obj = Stock.objects.get(sid=stock_id)
            obj.quant = obj.quant - int(quantity)
            if obj.quant >= 0:
                obj.save()
            else:
                print("error")

        return redirect('index')
