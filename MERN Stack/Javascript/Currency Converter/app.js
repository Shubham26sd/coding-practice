/*
Follow these steps: 
-- Add this URL to the BASE_URL => https://cdn.jsdelivr.net/npm/@fawazahmed0/currency-api@latest/v1/currencies
-- Update this section of the code as below:
const URL = `${BASE_URL}/${fromCurr.value.toLowerCase()}.json`;
   let response = await fetch(URL);
   let data = await response.json();
   let rate = data[fromCurr.value.toLowerCase()][toCurr.value.toLowerCase()];
   let finalAmount = amtVal * rate;
   msg.innerText = `${amtVal} ${fromCurr.value} = ${finalAmount} ${toCurr.value}`;

Explanation:
The API link has changed because the repository was migrated. The new URL structure is different; it no longer uses /currencies/{currencyCode}/{currencyCode}, but instead only /currencies/{currencyCode}. In the original code, both fromCurr and toCurr were part of the BASE_URL, and the exchange rate was derived directly. However, with the updated API, there isn't a direct endpoint for both currencies. Instead, you need to fetch the JSON for fromCurr, and then extract the rate for toCurr from that data to calculate the final amount. */

const BASE_URL =
  "https://cdn.jsdelivr.net/npm/@fawazahmed0/currency-api@latest/v1/currencies";

const dropdowns = document.querySelectorAll(".dropdown select");
const btn = document.querySelector("form button");
const fromCurr = document.querySelector(".from select");
const toCurr = document.querySelector(".to select");
const msg = document.querySelector(".msg");

document.addEventListener("load",()=>{
    updateExchangeRate();
});

for (let select of dropdowns) {
  for (currCode in countryList) {
    let newOption = document.createElement("option");
    newOption.innerText = currCode;
    newOption.value = currCode;
    if (select.name === "from" && currCode == "USD") {
      newOption.selected = "selected";
    } else if (select.name === "to" && currCode == "INR") {
      newOption.selected = "selected";
    }
    select.append(newOption);
  }

  select.addEventListener("change", (evt) => {
    updateFlag(evt.target);
  });
}

const updateFlag = (element) => {
  let currCode = element.value;
  let countryCode = countryList[currCode];

  let newSrc = `https://flagsapi.com/${countryCode}/flat/64.png`;
  let img = element.parentElement.querySelector("img");
  img.src = newSrc;
};

btn.addEventListener("click", (evt) => {
  evt.preventDefault();
  updateExchangeRate();
});

const updateExchangeRate = async () => {
  let amount = document.querySelector(".amount input");
  let amtVal = amount.value;
  if (amtVal == "" || amtVal < 1) {
    amtVal = 1;
    amount.value = "1";
  }

  const URL = `${BASE_URL}/${fromCurr.value.toLowerCase()}.json`;
  let response = await fetch(URL);
  let data = await response.json();
  let rate = data[fromCurr.value.toLowerCase()][toCurr.value.toLowerCase()];
  let finalAmount = amtVal * rate;
  msg.innerText = `${amtVal} ${fromCurr.value} = ${finalAmount} ${toCurr.value}`;
};
