var remove=document.querySelectorAll(".btn-danger")
console.log(remove)
for(var i=0;i<remove.length;i++)
{
    var button=remove[i];
    button.addEventListener('click',function(){
        this.parentElement.parentElement.remove()
        updateCartTotal();
    })
    

}

function updateCartTotal(){
    var total=0;
    var cartLoop= document.querySelectorAll('.cart-items .cart-row')
    console.log(cartLoop);
    for(var i=0;i<cartLoop.length;i++)
    {
      var current=cartLoop[i];
      var price=parseFloat(current.getElementsByClassName('cart-price')[0].innerText.replace('$',''))
      console.log(price);
      var quantity=current.getElementsByClassName('cart-quantity-input')[0]
      total=(total+quantity.value*price)
      console.log(total);
      document.querySelector('.cart-total-price').innerText="$"+total;
    }
    document.querySelector('.cart-total-price').innerText="$"+total;
}