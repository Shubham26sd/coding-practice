// import React, { useEffect,useState } from "react";
import { useLoaderData } from "react-router-dom";

function Github() {
  //   const [data, setData] = useState([]);
  //   useEffect(() => {
  //     fetch("https://api.github.com/users/Shubham26sd")
  //       .then((res) => res.json())
  //       .then((data) => {
  //         console.log(data);
  //         setData(data);
  //       });
  //   }, []);

  const data = useLoaderData();

  return (
    <div className="text-center m-4 bg-gray-600 text-3xl text-white flex justify-center items-center gap-4 p-4 ">
      <img src={data.avatar_url} alt="Git picture" width={300} />
      Github followers: {data.followers}
    </div>
  );
}
export default Github;

export const githubInfoLoader = async () => {
  const response = await fetch("https://api.github.com/users/Shubham26sd");
  return response.json();
};
