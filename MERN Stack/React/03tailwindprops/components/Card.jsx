import React from "react";

function Card({ username,btnText="Click Here" }) {
  console.log(username);
  return (
    <div
      className="flex flex-col rounded-xl  p-4 mt-3"
      style={{
        border: "0.88px solid",

        backdropFilter: "saturate(180%) blur(14px)",
        background: " #ffffff0d",
      }}
    >
      <div>
        <img
          src="https://res.cloudinary.com/ddcg0rzlo/image/upload/v1652470298/9StaF0UBJfih_df0248.gif"
          alt="nft-gif"
          width="200"
          height="200"
          className="rounded-xl"
        />
      </div>
      <div className="flex flex-col  rounded-b-xl py-4 ">
        <div className="flex justify-between">
          <h2 className="font-RubikBold ">{username}</h2>
        </div>
        <div className="flex  justify-between font-mono"></div>
        <button className="mt-3">{btnText }</button>
      </div>
    </div>
  );
}

export default Card;
